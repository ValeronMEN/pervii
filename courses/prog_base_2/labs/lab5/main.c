#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "web.h"

#define MAX_BUFFER_SIZE 10000
#define MAX_PATIENT_SIZE 10
#define MY_PORT 5000
#define MAX_STRING_SIZE 100

int main(){
    lib_init(); // initialize lib of socket
    socket_t * mySocket = socket_new(); // create a new socket
    socket_bind(mySocket, MY_PORT); //bind socket with port
    socket_listen(mySocket);

    char buffer[MAX_BUFFER_SIZE];
    socket_t * client = NULL;
    patient_t PatientsReal[MAX_PATIENT_SIZE];
    patient_t * Patients[MAX_PATIENT_SIZE];

    char * db_name = "Patient.db";

    db_t * db = db_new(db_name);
    int size = db_count(db);
    //db_filter(db, 0.0, "lepra", *PatientsReal);
    printf("Opening %s database...\n", db_name);
    db_init(db, PatientsReal);
    patient_printList(PatientsReal, size);

    for (int i = 0; i < MAX_PATIENT_SIZE; i++){
        Patients[i] = patient_new();
        Patients[i] = &(PatientsReal[i]);
    }
    puts("");

    printf("Waiting for request...\n\n");

    while(1)
    {
        client = socket_accept(mySocket);
        socket_read(client, buffer, sizeof(buffer));

        if(strlen(buffer) != 0)
        {
            printf("Wow, we had a request!:\n%s\n", buffer);
            http_request_t request = http_request_parse(buffer);

            if (strcmp(request.uri, "/") == 0)
            {
                web_home(client);
            }
            else if (strcmp(request.uri, "/api/Patients") == 0)
            {
                web_api_patients(client, &request, Patients, &size, db, PatientsReal);
            }
            else if (strncmp(request.uri, "/api/Patients/", PATIENTS_API_LINE_SIZE) == 0)
            {
                web_api_patientID(client, &request, Patients, &size, db);
            }
            else if (strncmp(request.uri, "/Patients?", (PATIENTS_LINE_SIZE)) == 0)
            {
                web_html_patientFilter(client, &request, Patients, &size, db);
            }
            else if (strcmp(request.uri, "/Patients") == 0)
            {
                web_html_patients(client, &request, Patients, &size, db, PatientsReal);
            }
            else if (strncmp(request.uri, "/Patients/", PATIENTS_LINE_SIZE) == 0)
            {
                web_html_patientID(client, &request, Patients, &size, db);
            }
            else if (strcmp(request.uri, "/new-Patient") == 0)
            {
                web_html_patientsPost(client, &request, Patients, &size);
            }
            else
            {
                web_pageNotFound(client); //show message about page not found
            }
        }
    }

    for (int i = 0; i < MAX_PATIENT_SIZE; i++){
        patient_free(Patients[i]);
    }

    socket_free(client); // free socket accept
    socket_free(mySocket); // free mySocket
    lib_free(); // free lib of socket
    db_delete(db);

    return 0;
}
