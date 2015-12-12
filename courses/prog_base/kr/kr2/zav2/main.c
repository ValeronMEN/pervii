#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Student {
   time_t birthday;
   char name[100];
   struct Laptop * laptop;
};

struct Laptop{
   time_t realisedate;
   char mark[100];
};

void InitializeD(struct Student * students1, struct Student * students2){
    struct tm * pTime = (struct tm *)malloc(sizeof(struct tm));

    pTime->tm_mday = 9;
    pTime->tm_mon = 2;
    pTime->tm_year = 92;
    time_t a = mktime(pTime);

    students1->birthday = a;
    strcpy(students1->name, "Igor");
    students1->laptop->realisedate = a;
    strcpy(students1->laptop->mark, "Asus");

    students2->birthday = a;
    strcpy(students2->name, "Vanya");
    students2->laptop->realisedate = a;
    strcpy(students2->laptop->mark, "Lenovo");

    free(pTime);
}

void InitializeR (struct Student * students1, struct Student * students2){
    struct tm * pTime = (struct tm *)malloc(sizeof(struct tm));

    pTime->tm_mday = 9;
    pTime->tm_mon = 2;
    pTime->tm_year = 92;
    time_t a = mktime(pTime);
    //printf("%s", ctime(&a));

    printf("Enter name of first student\n>> ");
    gets(students1->name);
    printf("Enter mark of first laptop\n>> ");
    gets(students1->laptop->mark);
    //students2->laptop->realisedate = ctime(&a);

    printf("Enter name of second student\n>> ");
    gets(students2->name);
    printf("Enter mark of first laptop\n>> ");
    gets(students2->laptop->mark);

    free(pTime);

}

void PrintStudent(struct Student * students1){
    printf("Name of student: %s", students1->name);
    printf("Birthday of student: %s", ctime(students1->birthday));
    printf("Release date of student: %s", ctime(students1->birthday));
    printf("Mark of laptop, student: %s", students1->name);
}

int main()
{
    struct Student * students[2];
    printf("Enter structures data:\n\n");

    InitializeR(&(students[1]), &(students[2]));
    printf("Hello world!\n");
    return 0;
}
