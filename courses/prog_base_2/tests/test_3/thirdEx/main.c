#include <stdio.h>
#include <stdlib.h>

#include "module.h"

#define PATIENTS_MAX_SIZE 10
#define FILTER_CITY "Lvov"

int main(){
    db_t * db = db_new("Student.db");

    int size = db_count(db);
    printf("Students total in database: %i", size);
    puts("\n");


    student_t student_list_filtered[PATIENTS_MAX_SIZE];
    int filterCount = db_filter(db, FILTER_CITY, student_list_filtered, size);
    printf("Students from %s: %i", FILTER_CITY, filterCount);
    puts("\n");

    printf("List of patients with current statement:\n");
    student_printList(student_list_filtered, filterCount);
    puts("");

    student_t myStudent = {56, "Valeriy", "Sherstiuk", "Kalvovich", "Kanov", 90, "1995-05-09"};
    db_student_insert(db, &myStudent);

    db_student_delete(db, FILTER_CITY);

    //db_patient_delete(db, 0);

    return 0;
}
