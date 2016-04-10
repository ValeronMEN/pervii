#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <strings.h>
#include <libxml/tree.h>

#include "clinic.h"

void main(){
    int i;
    const char * filePath = "Patient.xml";
    patient_t * patients[3];

    for(i = 0; i < 3; i++){
        patients[i] = patient_new();
    }

    xmlParse(patients, filePath);

    for(i = 0; i < 3; i++){
        printf("PATIENT #%i\n", (i+1));
        print_function(patients[i]);
    }

    for(i = 0; i < 3; i++){
        patient_delete(patients[i]);
    }

    return;
}
