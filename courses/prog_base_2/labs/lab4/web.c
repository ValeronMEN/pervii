#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "web.h"

static int verification(char * name, char * surname, char * diagnosis, char * treatment, char * birthday, char * importance, char * roomnumber){
    int checkNum = 0;

    for (int i = 0; i < 4; i++){
        if (!isdigit(birthday[i])){
            checkNum++;
        }
    }
    if (birthday[4] != '-'){
        checkNum++;
    }
    for (int i = 5; i < 7; i++){
        if (!isdigit(birthday[i])){
            checkNum++;
        }
    }
    if (atoi(birthday + 5) > 12){
        checkNum++;
    }
    if (birthday[7] != '-'){
        checkNum++;
    }
    for (int i = 8; i < 10; i++){
        if (!isdigit(birthday[i])){
            checkNum++;
        }
    }
    if (atoi(birthday + 8) > 31){
        checkNum++;
    }

    for (int i = 0; i < strlen(roomnumber); i++){
        if (!isdigit(roomnumber[i])){
            checkNum++;
        }
    }

    int countDot = 0;
    for (int i = 0; i < strlen(importance); i++)
    {
        if (!isdigit(importance[i]) && importance[i] != '.')
        {
            checkNum++;
        }
        if (importance[i] == '.')
        {
            countDot++;
        }
    }
    if (countDot > 1)
    {
        checkNum++;
    }

    if (strlen(name) == 0 || strlen(surname) == 0 || strlen(diagnosis) == 0 || strlen(treatment) == 0 || strlen(birthday) != 10
            || strlen(roomnumber) == 0 || strlen(importance) == 0
            || strlen(name) > 20 || strlen(surname) > 20 || strlen(roomnumber) > 5
       )
    {
        checkNum++;
    }

    if (checkNum == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static char * json_bufferInit(char * text){
    char * buffer = malloc(sizeof(char) * BIG_BUFFER_SIZE);

    sprintf(buffer,
            "HTTP/1.1 200 OK\n"
            "Content-Type: application/json\n"
            "Content-Length: %zu\n"
            "Connection: keep-alive\n"
            "\n%s", strlen(text), text);

    return buffer;
}

static char * html_bufferInit(char * text){
    char * buffer = malloc(sizeof(char) * BIG_BUFFER_SIZE);

    sprintf(buffer,
            "HTTP/1.1 200 OK\n"
            "Content-Type: text/html\n"
            "Content-Length: %zu\n"
            "\n%s", strlen(text), text);

    return buffer;
}

void web_home(socket_t * client){
    char buffer[SMALL_BUFFER_SIZE] = "";
    char * pageText =
        "<html>"
        "<head>"
        "</head>"
        "<body>"
        "<h1>Zdrastie, Ruslan Anatolievich!</h1>"
        "<a href=\"http://127.0.0.1:5000/Patients\">All Patients. Let's look at these weak-minded!</a>"
        "</body>"
        "</html>";

    char * text = html_bufferInit(pageText);
    strcat(buffer, text);

    socket_write_string(client, pageText);

    free(text);
    socket_close(client);
}

void web_pageNotFound(socket_t * client){
    char buffer[SMALL_BUFFER_SIZE] = "";
    char * pageText = "I'm sorry, but page not found =(";

    char * text = html_bufferInit(pageText);
    strcat(buffer, text);
    free(text);

    socket_write_string(client, buffer);
    socket_close(client);
}

void web_patients(socket_t * client, http_request_t * req, patient_t ** Patients, int * size){
    char buffer[BIG_BUFFER_SIZE] = "";

    if (strcmp(req->method, "GET") == 0)
    {
        char text[BIG_BUFFER_SIZE] = "";
        char * jsonPatient = NULL;

        strcat(text, "[");
        for(int i = 0; i < (*size); i++)
        {
            if(i == (*size) - 1)
                jsonPatient = patient_json(Patients[i]);
            else
                jsonPatient = patient_json(Patients[i]);

            strcat(text, jsonPatient);
            if(i !=  (*size) - 1) strcat(text, ",");
        }
        strcat(text, "]");

        char * textHTML = json_bufferInit(text);
        strcat(buffer, textHTML);
        free(textHTML);
    }
    else if (strcmp(req->method, "POST") == 0)
    {
        char * name = (char *)http_request_getArg(req, "name");
        char * surname = (char *)http_request_getArg(req, "surname");
        char * diagnosis = (char *)http_request_getArg(req, "diagnosis");
        char * treatment = (char *)http_request_getArg(req, "treatment");
        char * birthday = (char *)http_request_getArg(req, "birthday");
        char * importance = (char *)http_request_getArg(req, "importance");
        char * roomnumber = (char *)http_request_getArg(req, "roomnumber");

        if(verification(name, surname, diagnosis, treatment, birthday, importance, roomnumber) == 1)
        {
            char pageText[SMALL_BUFFER_SIZE] = "";
            patient_init(Patients[*size], name, surname, diagnosis, treatment, birthday, atof(importance), atoi(roomnumber));
            char * jsonPatient = patient_json(Patients[*size]);
            strcat(pageText, jsonPatient);
            (*size)++;

            char * textHTML = json_bufferInit(pageText);
            strcat(buffer, textHTML);
            free(textHTML);
        }
        else
        {
            char * pageText = "{\n    \"Error\": \"Wrong input\"\n}";
            char * textHTML = json_bufferInit(pageText);
            strcat(buffer, textHTML);
            free(textHTML);
        }
    }

    socket_write_string(client, buffer);
    socket_close(client);
}

void web_patientID(socket_t * client, http_request_t * req, patient_t ** Patients, int * size){
    char buffer[BIG_BUFFER_SIZE] = "";

    if (strcmp(req->method, "GET") == 0){
        char * point = strstr(req->uri, "/api/Patients/");
        point += PATIENTS_API_LINE_SIZE;
        int index = atoi(point);

        if(0 <= index && index < (*size)){
            char pageText[SMALL_BUFFER_SIZE] = "";
            char * jsonPatient = patient_json(Patients[index]);
            strcat(pageText, jsonPatient);
            char * textHTML = json_bufferInit(pageText);
            strcat(buffer, textHTML);
            free(textHTML);
        }
        else
        {
            char * pageText = "{\n    \"Error\": \"ID Not Found\"\n}";
            char * textHTML = json_bufferInit(pageText);
            strcat(buffer, textHTML);
            free(textHTML);
        }
    }
    else if (strcmp(req->method, "DELETE") == 0)
    {
        char * id = (char *)http_request_getArg(req, "id");
        int index = atoi(id);

        if(0 <= index && index < (*size))
        {
            for(int i = index; i < (*size) - 1; i++)
            {
                patient_swap(Patients[i], Patients[i + 1]);
            }

            (*size)--;

            char * pageText = "{\n    \"Success\": \"Successfully deleted\"\n}";
            char * textHTML = json_bufferInit(pageText);
            strcat(buffer, textHTML);
            free(textHTML);
        }
        else
        {
            char * pageText = "{\n    \"Error\": \"ID Not Found\"\n}";
            char * textHTML = json_bufferInit(pageText);
            strcat(buffer, textHTML);
            free(textHTML);
        }
    }

    socket_write_string(client, buffer);
    socket_close(client);
}

void web_patientsHtml(socket_t * client, http_request_t * req, patient_t ** Patients, int * size){
    char buffer[BIG_BUFFER_SIZE] = "";

    if (strcmp(req->method, "GET") == 0)
    {
        char text[BIG_BUFFER_SIZE] = "";

        for(int i = 0; i < (*size); i++)
        {
            char pageText[100] = "";
            sprintf(pageText, "<a href=\"http://127.0.0.1:5000/Patients/%i\">%s %s<br></a>\n", i, patient_getSurname(Patients[i]), patient_getName(Patients[i]));
            strcat(text, pageText);
        }

        char * pageText = "<a href=\"http://127.0.0.1:5000/new-Patient\"><br>New Patient</a>";
        strcat(text, pageText);

        char * textHTML = html_bufferInit(text);
        strcat(buffer, textHTML);
        free(textHTML);
    }
    else if (strcmp(req->method, "POST") == 0)
    {
        char * name = (char *)http_request_getArg(req, "name");
        char * surname = (char *)http_request_getArg(req, "surname");
        char * diagnosis = (char *)http_request_getArg(req, "diagnosis");
        char * treatment = (char *)http_request_getArg(req, "treatment");
        char * birthday = (char *)http_request_getArg(req, "birthday");
        char * importance = (char *)http_request_getArg(req, "importance");
        char * roomnumber = (char *)http_request_getArg(req, "roomnumber");

        if(verification(name, surname, diagnosis, treatment, birthday, importance, roomnumber) == 1)
        {
            patient_init(Patients[*size], name, surname, diagnosis, treatment, birthday, atof(importance), atoi(roomnumber));
            char * pageText = "<h3>Success</h3>";
            (*size)++;

            char * textHTML = html_bufferInit(pageText);
            strcat(buffer, textHTML);
            free(textHTML);
        }
        else
        {
            char * pageText = "<h3>Wrong input</h3>";
            char * textHTML = html_bufferInit(pageText);
            strcat(buffer, textHTML);
            free(textHTML);
        }
    }

    socket_write_string(client, buffer);
    socket_close(client);
}

void web_patientsHtmlPost(socket_t * client, http_request_t * req, patient_t ** Patients, int * size){
    char buffer[BIG_BUFFER_SIZE] = "";

    if (strcmp(req->method, "GET") == 0)
    {
        char * pageText =
            "<html>"
            "<head>"
            "</head>"
            "<body>"
            "<form action=\"http://127.0.0.1:5000/Patients\" method=\"POST\">"
            "Name:<br>"
            "<input type=\"text\" name=\"name\" value='Name'><br>"
            "Surname:<br>"
            "<input type=\"text\" name=\"surname\" value='Surname'><br>"
            "Diagnosis:<br>"
            "<input type=\"text\" name=\"diagnosis\" value='Diagnosis'><br>"
            "Treatment:<br>"
            "<input type=\"text\" name=\"treatment\" value='Treatment'><br>"
            "Birthday:<br>"
            "<input type=\"text\" name=\"birthday\" value='1900-01-01'><br>"
            "Importance:<br>"
            "<input type=\"text\" name=\"importance\" value='0.0'><br>"
            "Roomnumber:<br>"
            "<input type=\"text\" name=\"roomnumber\" value='0'><br><br>"

            "<input type=\"submit\" value='Submit!' />"
            "</form>"
            "</body>"
            "</html>";

            char * textHTML = html_bufferInit(pageText);
            strcat(buffer, textHTML);
            free(textHTML);
    }

    socket_write_string(client, buffer);
    socket_close(client);
}

void web_patientIDHtml(socket_t * client, http_request_t * req, patient_t ** Patients, int * size){
    char buffer[BIG_BUFFER_SIZE] = "";

    char * point = strstr(req->uri, "/Patients/");
    point += PATIENTS_LINE_SIZE;
    int index = atoi(point);

    if(0 <= index && index < (*size))
    {
        if (strcmp(req->method, "GET") == 0)
        {
            char pageText[SMALL_BUFFER_SIZE] = "";
            char * text = patient_html(Patients[index], index);
            strcat(pageText, text);
            free(text);

            char * textHTML = html_bufferInit(pageText);
            strcat(buffer, textHTML);
            free(textHTML);
        }
        else if (strcmp(req->method, "DELETE") == 0)
        {
            for(int i = index; i < (*size) - 1; i++)
            {
                patient_swap(Patients[i], Patients[i + 1]);
            }

            (*size)--;

            sprintf(buffer,
                    "HTTP/1.1 200 OK\n"
                    "Access-Control-Allow-Origin: *\n"
                    "Access-Control-Allow-Methods: DELETE\n"
                    "\n");
        }
    }
    else{
        char * pageText = "<h4>ID Not Found!</h4>";
        char * textHTML = html_bufferInit(pageText);
        strcat(buffer, textHTML);
        free(textHTML);
    }

    socket_write_string(client, buffer);
    socket_close(client);
}
