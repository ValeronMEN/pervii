#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "patient.h"

struct patient_s{
    char name[MAX_PATIENT_STR_SIZE];
    char surname[MAX_PATIENT_STR_SIZE];
    char diagnosis[MAX_PATIENT_STR_SIZE];
    char treatment[MAX_PATIENT_STR_SIZE];
    char birthday[MAX_DATE_STR_SIZE];
    double importance;
    int roomnumber;
};

patient_t * patient_new(void){
    return malloc(sizeof(struct patient_s));
}

void patient_free(patient_t * self){
    free(self);
}

void patient_init(patient_t * self, char * name, char * surname, char * diagnosis, char * treatment, char * birthday, double importance, int roomnumber){
    strcpy(self->name, name);
    strcpy(self->surname, surname);
    strcpy(self->diagnosis, diagnosis);
    strcpy(self->treatment, treatment);
    strcpy(self->birthday, birthday);
    self->importance = importance;
    self->roomnumber = roomnumber;
}

void patient_swap(patient_t * self, patient_t * selfSwap){
    strcpy(self->name, selfSwap->name);
    strcpy(self->surname, selfSwap->surname);
    strcpy(self->diagnosis, selfSwap->diagnosis);
    strcpy(self->treatment, selfSwap->treatment);
    strcpy(self->birthday, selfSwap->birthday);
    self->importance = selfSwap->importance;
    self->roomnumber = selfSwap->roomnumber;
}

char * patient_json(patient_t * self){
    cJSON * patientObject = cJSON_CreateObject(); // create an object

    cJSON_AddItemToObject(patientObject, "name", cJSON_CreateString(self->name)); // add item to object
    cJSON_AddItemToObject(patientObject, "surname", cJSON_CreateString(self->surname));
    cJSON_AddItemToObject(patientObject, "diagnosis", cJSON_CreateString(self->diagnosis));
    cJSON_AddItemToObject(patientObject, "treatment", cJSON_CreateString(self->treatment));
    cJSON_AddItemToObject(patientObject, "birthday", cJSON_CreateString(self->birthday));
    cJSON_AddItemToObject(patientObject, "importance", cJSON_CreateNumber(self->importance));
    cJSON_AddItemToObject(patientObject, "roomnumber", cJSON_CreateNumber(self->roomnumber));

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
            "Name: %s<br>"
            "Surname: %s<br>"
            "Diagnosis: %s<br>"
            "Treatment: %s<br>"
            "Birthday: %s<br>"
            "Importance: %.1f<br>"
            "Roomnumber: %i<br>"
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
            self->name, self->surname, self->diagnosis, self->treatment, self->birthday, self->importance, self->roomnumber, ID);

    strcpy(text, pageText); // include our strings to text

    return text;
}

char * patient_getName(patient_t * self){
    return self->name;
}

char * patient_getSurname(patient_t * self){
    return self->surname;
}
