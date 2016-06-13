#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "C:\Users\DrLove\Desktop\thirdEx\sqlite3.h"
#include "module.h"

#ifndef TRUE
#define TRUE 1
#endif // TRUE

struct db_s{
    sqlite3 * db;
};

static void errorHandler_NotEqual(int returnCode, int errorToCmp, const char *errorMsg){
    if(errorToCmp != returnCode)
    {
        fprintf(stderr, "ERROR: [%s].\n", errorMsg);
        exit(1);
    }
}

static void errorHandler_Equal(int returnCode, int errorToCmp, const char *errorMsg){
    if(errorToCmp == returnCode)
    {
        fprintf(stderr, "ERROR: [%s].\n", errorMsg);
        exit(1);
    }
}

db_t * db_new(char *dbPath){
    db_t * out = (db_t *) malloc(sizeof(struct db_s));
    int returnCode = sqlite3_open(dbPath, &out->db);
    errorHandler_NotEqual(returnCode, SQLITE_OK, "Cannot open database.\n");
    return (out);
}

void db_delete(db_t * self){
    int returnCode = sqlite3_close(self->db);
    errorHandler_NotEqual(returnCode, SQLITE_OK, "Cannot close database.\n");
    free(self);
}

void db_student_insert(db_t * self, student_t * student){
    sqlite3_stmt *stmt = NULL;
    const char *sqlInsertCommand = "INSERT INTO Patient ('Name', 'Surname', 'Fathername', 'City', 'Number', 'Birthdate') VALUES (?,?,?,?,?,?);";
    int returnCode = 0;

    returnCode = sqlite3_prepare_v2(self->db, sqlInsertCommand, strlen(sqlInsertCommand) + 1, &stmt, NULL);
    errorHandler_NotEqual(returnCode, SQLITE_OK, "Sql insert command wasn`t prepared.");

    sqlite3_bind_text(stmt, 1, student->name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, student->surname, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, student->father, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, student->city, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 5, student->number);
    sqlite3_bind_text(stmt, 6, student->birthdate, -1, SQLITE_STATIC);

    returnCode = sqlite3_step(stmt);
    errorHandler_NotEqual(returnCode, SQLITE_DONE, "Data wasn`t inserted.");

    student->id = (int)sqlite3_last_insert_rowid(self->db);
    sqlite3_reset(stmt);
}

student_t * db_student_get(db_t * self, int id){
    student_t * toGet = (student_t *)malloc(sizeof(struct student_s));
    sqlite3_stmt * stmt = NULL;
    const char *sqlGetCommand = "SELECT * FROM Patient WHERE Id=?;";
    int returnCode = 0;

    sqlite3_prepare_v2(self->db, sqlGetCommand, strlen(sqlGetCommand) + 1, &stmt, NULL);
    errorHandler_NotEqual(returnCode, SQLITE_OK, "Sql select command wasn`t prepared.");
    sqlite3_bind_int(stmt, 1, id);
    returnCode = sqlite3_step(stmt);
    if(returnCode != SQLITE_ROW)
    {
        toGet->id = 0;
        strcpy(toGet->name, "EMPTY");
        strcpy(toGet->surname, "EMPTY");
        strcpy(toGet->father, "EMPTY");
        strcpy(toGet->city, "EMPTY");
        toGet->number = 0;
        strcpy(toGet->birthdate, "EMPTY");
        return (toGet);
    }
    toGet->id = id;
    strcpy(toGet->name, (char *)sqlite3_column_text(stmt, 1));
    strcpy(toGet->surname, (char *)sqlite3_column_text(stmt, 2));
    strcpy(toGet->father, (char *)sqlite3_column_text(stmt, 3));
    strcpy(toGet->city, (char *)sqlite3_column_text(stmt, 4));
    toGet->number = sqlite3_column_int(stmt, 5);
    strcpy(toGet->birthdate, (char *)sqlite3_column_text(stmt, 6));

    sqlite3_reset(stmt);
    return (toGet);
}

void db_patient_delete(db_t * self, int id){
    sqlite3_stmt *stmt = NULL;
    const char *sqlDeleteCommand = "DELETE FROM Student WHERE Id=?";
    int returnCode = 0;

    sqlite3_prepare_v2(self->db, sqlDeleteCommand, strlen(sqlDeleteCommand) + 1, &stmt, NULL);
    errorHandler_NotEqual(returnCode, SQLITE_OK, "Error preparing delete command.");

    sqlite3_bind_int(stmt, 1, id);

    sqlite3_step(stmt);
    sqlite3_reset(stmt);
}

int db_count(db_t * self){
    sqlite3_stmt * stmt = NULL;
    const char *sqlCountCommand = "SELECT COUNT(*) FROM Student";
    int returnCode = 0;
    int studentsCount = 0;
    returnCode = sqlite3_prepare_v2(self->db, sqlCountCommand, strlen(sqlCountCommand) + 1, &stmt, NULL);
    errorHandler_NotEqual(returnCode, SQLITE_OK, "Error preparing statement by COUNT(*) command.\n");
    returnCode = sqlite3_step(stmt);
    errorHandler_Equal(returnCode, SQLITE_ERROR, "Error by stepping with COUNT(*) command.\n");
    studentsCount = sqlite3_column_int(stmt, 0);
    return (studentsCount);
}

static void db_patient_fill(sqlite3_stmt * stmt, student_t * student){
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char *name = sqlite3_column_text(stmt, 1);
    const unsigned char *surname = sqlite3_column_text(stmt, 2);
    const unsigned char *father = sqlite3_column_text(stmt, 3);
    const unsigned char *city = sqlite3_column_text(stmt, 4);
    int number = sqlite3_column_int(stmt, 5);
    const unsigned char *birthdate = sqlite3_column_text(stmt, 6);

    student->id = id;
    strcpy(student->name, (char *)name);
    strcpy(student->surname, (char *)surname);
    strcpy(student->father, (char *)father);
    strcpy(student->city, (char *)city);
    student->number = number;
    strcpy(student->birthdate, (char *)birthdate);
}

int db_filter(db_t * self, char * city, student_t * studentSet, int setMaxLen){
    sqlite3_stmt *stmt = NULL;
    const char *sqlCommand = "SELECT * FROM Student WHERE City LIKE ?;";
    int returnCode = 0;
    int patientSetIndex = 0;

    sqlite3_prepare_v2(self->db, sqlCommand, strlen(sqlCommand) + 1, &stmt, NULL);
    errorHandler_NotEqual(returnCode, SQLITE_OK, "Error preparing statement by SELECT * command.\n");
    sqlite3_bind_text(stmt, 1, city, -1, SQLITE_STATIC);
    while(TRUE)
    {
        int returnCode2 = sqlite3_step(stmt);
        if(returnCode2 == SQLITE_ERROR)
        {
            fprintf(stderr, "Can`t select patients.\n");
            exit(1);
        }
        if(SQLITE_DONE == returnCode2)
        {
            break;
        }
        else
        {
            db_patient_fill(stmt, &studentSet[patientSetIndex]);
            patientSetIndex++;
        }
    }
    returnCode = sqlite3_finalize(stmt);
    errorHandler_NotEqual(returnCode, SQLITE_OK, "Error destroying statement.");
    return (patientSetIndex);
}
