#include <stdio.h>
#include <stdlib.h>

#include "module.h"

#define PATIENTS_MAX_SIZE 10
#define FILTER_DAYS 4.0
#define FILTER_DIAGNOSIS 890977

int main(){
    db_t * db = db_new("Patient.db");

    int size = db_count(db);
    printf("Patients total in database: %i", size);
    puts("\n");

    patient_t patient_list_filtered[PATIENTS_MAX_SIZE];
    int filterCount = db_filter(db, FILTER_DAYS, FILTER_DIAGNOSIS, patient_list_filtered, size);
    printf("1. Patients with more than %.1f days proceed\n2. Patients with %i diagnosis\n> %d count", FILTER_DAYS, FILTER_DIAGNOSIS, filterCount);
    puts("\n");

    printf("List of patients with current statement:\n");
    patient_printList(patient_list_filtered, filterCount);
    puts("");

    int specialid = 3;
    printf("Patient with %i id\n", specialid);
    patient_t * patienttocheck = db_patient_get(db, specialid);
    patient_print(patienttocheck);
    puts("");

    int updateid = 1;
    printf("Patient with id %i updated\n", updateid);
    patient_t updatepatient = {20, "Updated", "Updated", 890978, 2.0, 88, "1998-07-08"};
    db_patient_update(db, &updatepatient, 1);

    patient_t mypatient = {0, "Valeriy", "Sherstiuk", 879909, 5.0, 7, "1995-05-09"};
    db_patient_insert(db, &mypatient);

    //db_patient_delete(db, 0);

    return 0;
}
