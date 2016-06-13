#define STRING_MAX_SIZE 100

typedef struct student_s{
    int id;
    char name[STRING_MAX_SIZE];
    char surname[STRING_MAX_SIZE];
    char father[STRING_MAX_SIZE];
    char city[STRING_MAX_SIZE];
    int number;
    char birthdate[STRING_MAX_SIZE];
} student_t;

void student_print(const student_t * );
void student_printList(const student_t *, int);
