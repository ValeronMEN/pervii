#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "web.h"

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

void server_home(socket_t * client){
    char buffer[SMALL_BUFFER_SIZE] = "";
    char * pageText =
        "<h1>Zdrastie, Ruslan Anatolievich!</h1>"
        "<a href=\"http://127.0.0.1:5000/Patients\">All Patients</a>";

    char * text = html_bufferInit(pageText);
    strcat(buffer, text);
    free(text);

    socket_write_string(client, pageText);
    socket_close(client);
}

void server_pageNotFound(socket_t * client){
    char buffer[SMALL_BUFFER_SIZE] = "";
    char * pageText = "I'm sorry, but page not found =(";

    char * text = html_bufferInit(pageText);
    strcat(buffer, text);
    free(text);

    socket_write_string(client, buffer);
    socket_close(client);
}



void server_patientID(socket_t * client, http_request_t * req, patient_t ** Patients, int * size){
    char buffer[BIG_BUFFER_SIZE] = "";

    if (strcmp(req->method, "GET") == 0){
        char * point = strstr(req->uri, "/info");
        point += PATIENTS_API_LINE_SIZE;
        int index = atoi(point);

        if(0 <= index && index < (*size)){
            char pageText[SMALL_BUFFER_SIZE] = "";
            char * jSm = patient_json(Patients[index], 0);
            strcat(pageText, jSm);
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
