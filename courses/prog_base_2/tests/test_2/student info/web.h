#ifndef WEB_H_INCLUDED
#define WEB_H_INCLUDED

#include "patient.h"
#include "socket.h"
#include "http.h"

#define PATIENTS_LINE_SIZE 10
#define PATIENTS_API_LINE_SIZE 5

void server_home(socket_t * client);
void server_pageNotFound(socket_t * client);
void server_patientID(socket_t * client, http_request_t * req, patient_t ** Patients, int * size);

#endif // WEB_H_INCLUDED
