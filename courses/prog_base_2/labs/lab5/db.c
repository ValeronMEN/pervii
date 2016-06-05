#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "sqlite3.h"
#include "db.h"

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

void db_patient_insert(db_t * self, patient_t * patient){
    sqlite3_stmt *stmt = NULL;
    const char *sqlInsertCommand = "INSERT INTO Patient ('Name', 'Surname', 'Diagnosis', 'Days', 'Importance', 'Birthday') VALUES (?,?,?,?,?,?);";
    int returnCode = 0;

    returnCode = sqlite3_prepare_v2(self->db, sqlInsertCommand, strlen(sqlInsertCommand) + 1, &stmt, NULL);
    errorHandler_NotEqual(returnCode, SQLITE_OK, "Sql insert command wasn`t prepared.");

    sqlite3_bind_text(stmt, 1, patient->name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, patient->surname, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, patient->diagnosis, -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 4, patient->days);
    sqlite3_bind_int(stmt, 5, patient->importance);
    sqlite3_bind_text(stmt, 6, patient->birthdate, -1, SQLITE_STATIC);

    returnCode = sqlite3_step(stmt);
    errorHandler_NotEqual(returnCode, SQLITE_DONE, "Data wasn`t inserted.");

    patient->id = (int)sqlite3_last_insert_rowid(self->db);
    sqlite3_reset(stmt);
}

patient_t * db_patient_get(db_t * self, int id){
    patient_t * toGet = (patient_t *)malloc(sizeof(struct patient_s));
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
        strcpy(toGet->diagnosis, "EMPTY");
        toGet->days = 0.0;
        toGet->importance = 0;
        strcpy(toGet->birthdate, "EMPTY");
        return (toGet);
    }
    toGet->id = id;
    strcpy(toGet->name, (char *)sqlite3_column_text(stmt, 1));
    strcpy(toGet->surname, (char *)sqlite3_column_text(stmt, 2));
    strcpy(toGet->diagnosis, (char *)sqlite3_column_text(stmt, 3));
    toGet->days = sqlite3_column_double(stmt, 4);
    toGet->importance = sqlite3_column_int(stmt, 5);
    strcpy(toGet->birthdate, (char *)sqlite3_column_text(stmt, 6));

    sqlite3_reset(stmt);
    return (toGet);
}

void db_patient_update(db_t * self, patient_t * patient, int id){
    sqlite3_stmt *stmt = NULL;
    const char *sqlUpdateCommand = "UPDATE Patient SET "
                                   "Name=?,"
                                   "Surname=?,"
                                   "Diagnosis=?,"
                                   "Days=?,"
                                   "Importance=?,"
                                   "Birthdate=? "
                                   "WHERE Id=?;";
    int returnCode = 0;

    returnCode = sqlite3_prepare_v2(self->db, sqlUpdateCommand, strlen(sqlUpdateCommand) + 1, &stmt, NULL);
    errorHandler_NotEqual(returnCode, SQLITE_OK, "Error preparing update command.");

    sqlite3_bind_text(stmt, 1, patient->name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, patient->surname, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, patient->diagnosis, -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 4, patient->days);
    sqlite3_bind_int(stmt, 5, patient->importance);
    sqlite3_bind_text(stmt, 6, patient->birthdate, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 7, id);

    sqlite3_step(stmt);
    sqlite3_reset(stmt);
}

void db_patient_delete(db_t * self, int id){
    sqlite3_stmt *stmt = NULL;
    const char *sqlDeleteCommand = "DELETE FROM Patient WHERE Id=?";
    int returnCode = 0;

    sqlite3_prepare_v2(self->db, sqlDeleteCommand, strlen(sqlDeleteCommand) + 1, &stmt, NULL);
    errorHandler_NotEqual(returnCode, SQLITE_OK, "Error preparing delete command.");

    sqlite3_bind_int(stmt, 1, id);

    sqlite3_step(stmt);
    sqlite3_reset(stmt);
}

int db_count(db_t * self){
    sqlite3_stmt * stmt = NULL;
    const char *sqlCountCommand = "SELECT COUNT(*) FROM Patient";
    int returnCode = 0;
    int patientsCount = 0;
    returnCode = sqlite3_prepare_v2(self->db, sqlCountCommand, strlen(sqlCountCommand) + 1, &stmt, NULL);
    errorHandler_NotEqual(returnCode, SQLITE_OK, "Error preparing statement by COUNT(*) command.\n");
    returnCode = sqlite3_step(stmt);
    errorHandler_Equal(returnCode, SQLITE_ERROR, "Error by stepping with COUNT(*) command.\n");
    patientsCount = sqlite3_column_int(stmt, 0);
    return (patientsCount);
}

static int db_patient_fill(sqlite3_stmt * stmt, patient_t * patient){
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char *name = sqlite3_column_text(stmt, 1);
    const unsigned char *surname = sqlite3_column_text(stmt, 2);
    int diagnosis = sqlite3_column_text(stmt, 3);
    double days = sqlite3_column_double(stmt, 4);
    int importance = sqlite3_column_int(stmt, 5);
    const unsigned char *birthdate = sqlite3_column_text(stmt, 6);

    patient->id = id;
    strcpy(patient->name, (char *)name);
    strcpy(patient->surname, (char *)surname);
    strcpy(patient->diagnosis, (char *)diagnosis);
    patient->days = days;
    patient->importance = importance;
    strcpy(patient->birthdate, (char *)birthdate);

    return id;
}

int db_filter(db_t * self, double days, char * diagnosis, patient_t * patientSet, int less, int * indexes){
    sqlite3_stmt *stmt = NULL;
    const char *sqlCommand;
    if (less==1){
        sqlCommand = "SELECT * FROM Patient WHERE Days < ? AND Diagnosis LIKE ?;";
    }
    else{
        sqlCommand = "SELECT * FROM Patient WHERE Days > ? AND Diagnosis LIKE ?;";
    }

    int returnCode = 0;
    int patientSetIndex = 0;

    sqlite3_prepare_v2(self->db, sqlCommand, strlen(sqlCommand) + 1, &stmt, NULL);
    errorHandler_NotEqual(returnCode, SQLITE_OK, "Error preparing statement by SELECT * command.\n");
    sqlite3_bind_double(stmt, 1, days);
    sqlite3_bind_text(stmt, 2, diagnosis, -1, SQLITE_STATIC);
    int j=0;
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
            *(indexes+j) = db_patient_fill(stmt, &patientSet[patientSetIndex]);
            printf("%i\n", *(indexes+j));
            j++;
            patientSetIndex++;
        }
    }
    returnCode = sqlite3_finalize(stmt);
    errorHandler_NotEqual(returnCode, SQLITE_OK, "Error destroying statement.");
    return (patientSetIndex);
}

int db_init(db_t * self, patient_t * patientSet){
    sqlite3_stmt *stmt = NULL;
    const char *sqlCommand = "SELECT * FROM Patient;";
    int returnCode = 0;
    int patientSetIndex = 0;

    sqlite3_prepare_v2(self->db, sqlCommand, strlen(sqlCommand) + 1, &stmt, NULL);
    errorHandler_NotEqual(returnCode, SQLITE_OK, "Error preparing statement by SELECT * command.\n");
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
            db_patient_fill(stmt, &patientSet[patientSetIndex]);
            patientSetIndex++;
        }
    }
    returnCode = sqlite3_finalize(stmt);
    errorHandler_NotEqual(returnCode, SQLITE_OK, "Error destroying statement.");
    return (patientSetIndex);
}
