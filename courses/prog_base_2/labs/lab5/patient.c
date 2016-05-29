#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "patient.h"

patient_t * patient_new(void){
    return malloc(sizeof(struct patient_s));
}

void patient_free(patient_t * self){
    free(self);
}

void patient_init(patient_t * self, char * name, char * surname, char * diagnosis, char * birthday, double importance, double days, int id){
    strcpy(self->name, name);
    strcpy(self->surname, surname);
    strcpy(self->diagnosis, diagnosis);
    strcpy(self->birthday, birthday);
    self->importance = importance;
    self->days = days;
    self->id = id;
}

void patient_swap(patient_t * self, patient_t * selfSwap){
    strcpy(self->name, selfSwap->name);
    strcpy(self->surname, selfSwap->surname);
    strcpy(self->diagnosis, selfSwap->diagnosis);
    strcpy(self->birthday, selfSwap->birthday);
    self->importance = selfSwap->importance;
    self->days = selfSwap->days;
    self->id = selfSwap->id;
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
            "Importance: %.1f<br>"
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
            self->id, self->name, self->surname, self->diagnosis, self->birthday, self->importance, self->days, ID);

    strcpy(text, pageText); // include our strings to text

    return text;
}

char * patient_getName(patient_t * self){
    return self->name;
}

char * patient_getSurname(patient_t * self){
    return self->surname;
}

void patient_print(const patient_t * mypatient)
{
    printf("Name: %s\n"
           "Surname: %s\n"
           "Diagnosis: %i\n"
           "Days: %.1f\n"
           "Importance: %i\n"
           "Birthday: %s\n",
           mypatient->name,
           mypatient->surname,
           mypatient->diagnosis,
           mypatient->days,
           mypatient->importance,
           mypatient->birthday);
}

void patient_printList(const patient_t *dirSet, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        printf("\n%i.\n", (i+1));
        patient_print(&dirSet[i]);
        printf("");
    }
}
