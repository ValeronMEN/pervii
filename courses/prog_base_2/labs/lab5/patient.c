#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "patient.h"
#include "cJSON/cJSON.h"

patient_t * patient_new(void){
    return malloc(sizeof(struct patient_s));
}

void patient_free(patient_t * self){
    free(self);
}

void patient_init(patient_t * self, char * name, char * surname, char * diagnosis, char * birthdate, int importance, double days, int id){
    strcpy(self->name, name);
    strcpy(self->surname, surname);
    strcpy(self->diagnosis, diagnosis);
    strcpy(self->birthdate, birthdate);
    self->importance = importance;
    self->days = days;
    self->id = id;
}

void patient_swap(patient_t * self, patient_t * selfSwap){
    strcpy(self->name, selfSwap->name);
    strcpy(self->surname, selfSwap->surname);
    strcpy(self->diagnosis, selfSwap->diagnosis);
    strcpy(self->birthdate, selfSwap->birthdate);
    self->importance = selfSwap->importance;
    self->days = selfSwap->days;
    self->id = selfSwap->id;
}

char * patient_json(patient_t * self){
    cJSON * patientObject = cJSON_CreateObject(); // create an object

    cJSON_AddItemToObject(patientObject, "id", cJSON_CreateNumber(self->id));
    cJSON_AddItemToObject(patientObject, "name", cJSON_CreateString(self->name)); // add item to object
    cJSON_AddItemToObject(patientObject, "surname", cJSON_CreateString(self->surname));
    cJSON_AddItemToObject(patientObject, "diagnosis", cJSON_CreateString(self->diagnosis));
    cJSON_AddItemToObject(patientObject, "birthdate", cJSON_CreateString(self->birthdate));
    cJSON_AddItemToObject(patientObject, "importance", cJSON_CreateNumber(self->importance));
    cJSON_AddItemToObject(patientObject, "days", cJSON_CreateNumber(self->days));

    char * jsonPatient = cJSON_Print(patientObject); // create a text of json
    return jsonPatient;
}

char * patient_html(patient_t * self, int ID){
    char * text = malloc(sizeof(char) * BIG_BUFFER_SIZE);
    //strcpy(text, " "); // rubbish in text defeated

    char pageText[SMALL_BUFFER_SIZE] = "";
    sprintf(pageText,
            "<html>"
            "<head>"
            "</head>"
            "<body>"
            "<p>"
            "Id: %i<br>"
            "Name: %s<br>"
            "Surname: %s<br>"
            "Diagnosis: %s<br>"
            "Birthday: %s<br>"
            "Importance: %i<br>"
            "Days: %.1f<br>"
            "</p>"
            "<a href=\"#\" onclick=\"doDelete()\"/>Delete Patient<br><br></a>\n"
            "</body>"
            "<script>"
                "function doDelete() {"
                "var xhttp = new XMLHttpRequest();"
                "xhttp.open(\"DELETE\", \"http://127.0.0.1:5000/Patients/%i\", true);"
                "xhttp.send();"
                "}"
                "</script>"
                "</html>",
            self->id, self->name, self->surname, self->diagnosis, self->birthdate, self->importance, self->days, ID);

    strcpy(text, pageText); // include our strings to text

    return text;
}

char * patient_getName(patient_t * self){
    return self->name;
}

char * patient_getSurname(patient_t * self){
    return self->surname;
}

void patient_print(const patient_t * mypatient){
    printf("id: %i\n"
           "Name: %s\n"
           "Surname: %s\n"
           "Diagnosis: %s\n"
           "Days: %.1f\n"
           "Importance: %i\n"
           "Birthdate: %s\n",
           mypatient->id,
           mypatient->name,
           mypatient->surname,
           mypatient->diagnosis,
           mypatient->days,
           mypatient->importance,
           mypatient->birthdate);
}

void patient_printList(const patient_t *dirSet, int len){
    int i;
    for(i = 0; i < len; i++){
        printf("\n%i. ", (i+1));
        patient_print(&dirSet[i]);
        printf("");
    }
}
