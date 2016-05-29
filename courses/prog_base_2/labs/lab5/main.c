#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "web.h"
#include "db.h"

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
    patient_t * Patients[MAX_PATIENT_SIZE];

    for (int i = 0; i < MAX_PATIENT_SIZE; i++){
        Patients[i] = patient_new();
    }

    db_t * db = db_new("Patient.db");
    int size = db_count(db);

    for(int i; i < size; i++){
        db_init(db, Patients, size);
    }

    patient_printList(Patients, size);

    //

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
                server_home(client);
            }
            /*
            else if (strcmp(request.uri, "/api/Patients") == 0)
            {
                server_patients(client, &request, Patients, &size);
            }
            else if (strncmp(request.uri, "/api/Patients/", PATIENTS_API_LINE_SIZE) == 0)
            {
                server_patientID(client, &request, Patients, &size);
            }
            */
            else if (strcmp(request.uri, "/Patients") == 0)
            {
                server_patientsHtml(client, &request, Patients, &size);
            }
            else if (strncmp(request.uri, "/Patients/", PATIENTS_LINE_SIZE) == 0)
            {
                server_patientIDHtml(client, &request, Patients, &size);
            }
            else if (strcmp(request.uri, "/new-Patient") == 0)
            {
                server_patientsHtmlPost(client, &request, Patients, &size);
            }
            else
            {
                server_pageNotFound(client); //show message about page not found
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
