#ifndef WEB_H_INCLUDED
#define WEB_H_INCLUDED

#include "db.h"
#include "patient.h"
#include "socket.h"
#include "http.h"

#define PATIENTS_LINE_SIZE 10
#define PATIENTS_API_LINE_SIZE 14

void web_home(socket_t * client);
void web_pageNotFound(socket_t * client);
void web_api_patients(socket_t * client, http_request_t * req, patient_t ** Patients, int * size, db_t * db, patient_t *);
void web_api_patientID(socket_t * client, http_request_t * req, patient_t ** Patients, int * size, db_t* db);
void web_html_patients(socket_t * client, http_request_t * req, patient_t ** Patients, int * size, db_t * db, patient_t *);
void web_html_patientsPost(socket_t * client, http_request_t * req, patient_t ** Patients, int * size);
void web_html_patientID(socket_t * client, http_request_t * req, patient_t ** Patients, int * size, db_t* db);
void web_html_patientFilter(socket_t * client, http_request_t * req, patient_t ** Patients, int * size, db_t* db);

#endif // WEB_H_INCLUDED
