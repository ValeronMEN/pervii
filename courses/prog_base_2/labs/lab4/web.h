#ifndef WEB_H_INCLUDED
#define WEB_H_INCLUDED

#include "patient.h"
#include "socket.h"
#include "http.h"

#define PATIENTS_LINE_SIZE 10
#define PATIENTS_API_LINE_SIZE 14

void web_home(socket_t * client);
void web_pageNotFound(socket_t * client);
void web_patients(socket_t * client, http_request_t * req, patient_t ** Patients, int * size);
void web_patientID(socket_t * client, http_request_t * req, patient_t ** Patients, int * size);
void web_patientsHtml(socket_t * client, http_request_t * req, patient_t ** Patients, int * size);
void web_patientsHtmlPost(socket_t * client, http_request_t * req, patient_t ** Patients, int * size);
void web_patientIDHtml(socket_t * client, http_request_t * req, patient_t ** Patients, int * size);

#endif // WEB_H_INCLUDED
