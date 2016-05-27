#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "analysis.h"

void analysis(patient_t ** Patients){
    FILE * file = fopen("Patient.json", "r");
    char myText[MAX_BUFFER_SIZE];
    char myStr[MAX_STRING_SIZE];

    while(fgets(myStr, MAX_STRING_SIZE, file) != NULL){ // unite strings of file to myText
        strcat(myText, myStr);
    }
    fclose(file);

    cJSON * jList = cJSON_Parse(myText);
    if (!jList){
        printf("Error before: [%s]\n", cJSON_GetErrorPtr());
        return;
    }

    for (int i = 0; i < cJSON_GetArraySize(jList); i++){ // parse fields of .json
        cJSON * jItem = cJSON_GetArrayItem(jList, i);
        char * name = cJSON_GetObjectItem(jItem, "name")->valuestring;
        char * surname = cJSON_GetObjectItem(jItem, "surname")->valuestring;
        char * diagnosis = cJSON_GetObjectItem(jItem, "diagnosis")->valuestring;
        char * treatment = cJSON_GetObjectItem(jItem, "treatment")->valuestring;
        char * birthday = cJSON_GetObjectItem(jItem, "birthday")->valuestring;
        double importance = cJSON_GetObjectItem(jItem, "importance")->valuedouble;
        int roomnumber = cJSON_GetObjectItem(jItem, "roomnumber")->valueint;

        patient_init(Patients[i], name, surname, diagnosis, treatment, birthday, importance, roomnumber);
    }
    cJSON_Delete(jList);
}
