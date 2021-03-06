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
    student_t * Students[MAX_PATIENT_SIZE];
    int size = 1;

    for (int i = 0; i < MAX_PATIENT_SIZE; i++){
        Students[i] = student_new();
    }
    analysis(Students);

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
            else if (strncmp(request.uri, "/info", PATIENTS_API_LINE_SIZE) == 0)
            {
                server_studentID(client, &request, Students, &size);
            }
            else
            {
                server_pageNotFound(client); //show message about page not found
            }
        }
    }

    for (int i = 0; i < MAX_PATIENT_SIZE; i++){
        student_free(Students[i]);
    }

    socket_free(client); // free socket accept
    socket_free(mySocket); // free mySocket
    lib_free(); // free lib of socket
    return 0;
}
