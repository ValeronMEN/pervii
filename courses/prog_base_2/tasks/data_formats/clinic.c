#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <time.h>

#include "clinic.h"

static void diagnosis_function(diagnosis_t * diagnosis, xmlNode * curNode){
    char * data;
    for(curNode = curNode->children; curNode != NULL; curNode = curNode->next)
    {
        if(!xmlStrcmp(curNode->name, (const xmlChar *)"name"))
        {
            data = (char *)xmlNodeGetContent(curNode);
            strcpy(diagnosis->name, data);
            continue;
        }
        if(!xmlStrcmp(curNode->name, (const xmlChar *)"risk"))
        {
            data = (char *)xmlNodeGetContent(curNode);
            diagnosis->risk = atoi(data);
            continue;
        }
    }
}

static patient_t * patient_function(patient_t * current, xmlNode * curNode){
    char *data;
    char *properties;

    properties = (char *) xmlGetProp(curNode, (const xmlChar *)"name");
    strcpy(current->name, properties);
    properties = (char *)xmlGetProp(curNode, (const xmlChar *)"surname");
    strcpy(current->surname, properties);
    for(curNode = curNode->children; curNode != NULL; curNode = curNode->next)
    {
        if(!xmlStrcmp(curNode->name, (const xmlChar *)"treatment"))
        {
            data = (char *)xmlNodeGetContent(curNode);
            strcpy(current->treatment, data);
            continue;
        }
        if(!xmlStrcmp(curNode->name, (const xmlChar *)"birthday"))
        {
            data = (char *)xmlNodeGetContent(curNode);
            sscanf(data, "%d-%d-%d",
                   &current->birthday.tm_year,
                   &current->birthday.tm_mday,
                   &current->birthday.tm_mon);
            continue;
        }
        if(!xmlStrcmp(curNode->name, (const xmlChar *)"importance"))
        {
            data = (char *)xmlNodeGetContent(curNode);
            current->importance = atof(data);
            continue;
        }
        if(!xmlStrcmp(curNode->name, (const xmlChar *)"roomnumber"))
        {
            data = (char *)xmlNodeGetContent(curNode);
            current->roomnumber = atoi(data);
            continue;
        }
        if(!xmlStrcmp(curNode->name, (xmlChar *)"diagnosis"))
        {
            startup_from_xml(&(current->diagnosis), curNode);
            continue;
        }
    }
    return current;
}

patient_t * patient_new(){
    patient_t * patient = (patient_t *)malloc(sizeof(struct patient_s));
    strcpy(patient->name, "");
    strcpy(patient->surname, "");
    strcpy(patient->treatment, "");
    memset(&patient->birthday, 0, sizeof(patient->birthday));
    patient->importance = 0;
    patient->roomnumber = 0;
    strcpy(patient->diagnosis.name, "");
    patient->diagnosis.risk = 0;
    return patient;
}

void patient_delete(patient_t * mypatient){
    free(mypatient);
}

void xmlParse(patient_t ** patientSet, const char * XMLFileName){
    xmlDoc * doc = xmlReadFile(XMLFileName, "UTF-8", 0);
    if(doc == NULL)
    {
        xmlFreeDoc(doc);
        return;
    }
    xmlNode *xml_root = xmlDocGetRootElement(doc);
    xmlNode *curNode;
    int i;
    for(i = 0, curNode = xml_root->children; curNode != NULL; curNode = curNode->next)
    {
        if(!xmlStrcmp(curNode->name, (const xmlChar *)"patient"))
        {
            patient_function(patientSet[i++], curNode);
        }
    }
    xmlFreeDoc(doc);
}

void print_function(patient_t * patient){
    printf("\t[%s]\n"
           "\t[%s]\n"
           "\t[%s]\n"
           "\t%d-%d-%d\n"
           "\t%f\n"
           "\t%i\n"
           "\t[%s]\n"
           "\t%i\n\n",
           patient->name,
           patient->surname,
           patient->treatment,
           patient->birthday.tm_year, patient->birthday.tm_mon, patient->birthday.tm_mday,
           patient->importance,
           patient->roomnumber,
           patient->diagnosis.name,
           patient->diagnosis.risk
          );
}
