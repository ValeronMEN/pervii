#define STRING_MAX_SIZE 100

typedef struct patient_s{
    int id;
    char name[STRING_MAX_SIZE];
    char surname[STRING_MAX_SIZE];
    int diagnosis;
    double days;
    int importance;
    char birthdate[STRING_MAX_SIZE];
} patient_t;

void patient_print(const patient_t * );
void patient_printList(const patient_t *, int);
