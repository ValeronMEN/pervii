#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "analysis.h"

int main(){
    lib_init(); // initialize lib of socket
    socket_t * mySocket = socket_new(); // create a new socket
    socket_bind(mySocket, MY_PORT); //bind socket with port
    socket_listen(mySocket);

    char buffer[MAX_BUFFER_SIZE];
    socket_t * client = NULL;
    patient_t * Patients[MAX_PATIENT_SIZE];
    int size = 5;

    for (int i = 0; i < MAX_PATIENT_SIZE; i++){
        Patients[i] = patient_new();
    }
    analysis(Patients);

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
                web_patients(client, &request, Patients, &size);
            }
            else if (strncmp(request.uri, "/api/Patients/", PATIENTS_API_LINE_SIZE) == 0)
            {
                web_patientID(client, &request, Patients, &size);
            }
            else if (strcmp(request.uri, "/Patients") == 0)
            {
                web_patientsHtml(client, &request, Patients, &size);
            }
            else if (strncmp(request.uri, "/Patients/", PATIENTS_LINE_SIZE) == 0)
            {
                web_patientIDHtml(client, &request, Patients, &size);
            }
            else if (strcmp(request.uri, "/new-Patient") == 0)
            {
                web_patientsHtmlPost(client, &request, Patients, &size);
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
    return 0;
}
