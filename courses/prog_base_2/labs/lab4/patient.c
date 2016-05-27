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

char * patient_json(patient_t * self, int check){
    cJSON * SM = cJSON_CreateObject();

    cJSON_AddItemToObject(SM, "name", cJSON_CreateString(self->name));
    cJSON_AddItemToObject(SM, "surname", cJSON_CreateString(self->surname));
    cJSON_AddItemToObject(SM, "diagnosis", cJSON_CreateString(self->diagnosis));
    cJSON_AddItemToObject(SM, "treatment", cJSON_CreateString(self->treatment));
    cJSON_AddItemToObject(SM, "birthday", cJSON_CreateString(self->birthday));
    cJSON_AddItemToObject(SM, "importance", cJSON_CreateNumber(self->importance));
    cJSON_AddItemToObject(SM, "roomnumber", cJSON_CreateNumber(self->roomnumber));

    char * jsonSM = cJSON_Print(SM);
    return jsonSM;
}

char * patient_html(patient_t * self, int ID){
    char * text = malloc(sizeof(char) * BIG_BUFFER_SIZE);
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
            "</body>"
            "</html>",
            self->name, self->surname, self->diagnosis, self->treatment, self->birthday, self->importance, self->roomnumber);

    strcat(text, pageText);

    char * pageTextLink = "<a href=\"#\" onclick=\"doDelete()\"/>Delete Patient<br><br></a>\n";
    strcat(text, pageTextLink);

    char pageTextScript[SMALL_BUFFER_SIZE];
    sprintf(pageTextScript,
                "<script>"
                "function doDelete() {"
                "var xhttp = new XMLHttpRequest();"
                "xhttp.open(\"DELETE\", \"http://127.0.0.1:5000/Patients/%i\", true);"
                "xhttp.send();"
                "}"
                "</script>", ID);
    strcat(text, pageTextScript);

    return text;
}

char * patient_getName(patient_t * self){
    return self->name;
}

char * patient_getSurname(patient_t * self){
    return self->surname;
}
