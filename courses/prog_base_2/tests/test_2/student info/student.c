#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "student.h"

struct student_s{
    char name[MAX_PATIENT_STR_SIZE];
    char group[MAX_PATIENT_STR_SIZE];
    int variant;
};

student_t * student_new(void){
    return malloc(sizeof(struct student_s));
}

void student_free(student_t * self){
    free(self);
}

void student_init(student_t * self, char * name, char * group, int variant){
    strcpy(self->name, name);
    strcpy(self->group, group);
    self->variant = variant;
}

void student_swap(student_t * self, student_t * selfSwap){
    strcpy(self->name, selfSwap->name);
    strcpy(self->group, selfSwap->group);
    self->variant = selfSwap->variant;
}

char * student_json(student_t * self, int check){
    cJSON * SM = cJSON_CreateObject();

    cJSON_AddItemToObject(SM, "student", cJSON_CreateString(self->name));
    cJSON_AddItemToObject(SM, "group", cJSON_CreateString(self->group));
    cJSON_AddItemToObject(SM, "variant", cJSON_CreateNumber(self->variant));

    char * jsonSM = cJSON_Print(SM);
    return jsonSM;
}

char * student_html(student_t * self, int ID){
    char * text = malloc(sizeof(char) * BIG_BUFFER_SIZE);
    char pageText[SMALL_BUFFER_SIZE] = "";

    sprintf(pageText,
            "<html>"
            "<head>"
            "</head>"
            "<body>"
            "<p>"
            "Student: %s<br>"
            "Group: %s<br>"
            "Variant: %i<br>"
            "</p>"
            "</body>"
            "</html>",
            self->name, self->group, self->variant);

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

char * student_getName(student_t * self){
    return self->name;
}

char * student_getGroup(student_t * self){
    return self->group;
}
