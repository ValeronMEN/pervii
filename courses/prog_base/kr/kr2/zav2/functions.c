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
    /*struct tm * pTime = (struct tm *)malloc(sizeof(struct tm));

    pTime->tm_mday = 9;
    pTime->tm_mon = 2;
    pTime->tm_year = 92;
    time_t a = mktime(pTime);*/

    students1->birthday = time(NULL);
    strcpy(students1->name, "Igor");
    students1->laptop->realisedate = time(NULL);
    strcpy(students1->laptop->mark, "Asus");

    students2->birthday = time(NULL);
    strcpy(students2->name, "Vanya");
    students2->laptop->realisedate = time(NULL);
    strcpy(students2->laptop->mark, "Lenovo");

    //free(pTime);
}

void InitializeR (struct Student * students1, struct Student * students2){
    char n[100];
    /*struct tm * pTime = (struct tm *)malloc(sizeof(struct tm));

    pTime->tm_mday = 9;
    pTime->tm_mon = 2;
    pTime->tm_year = 92;
    time_t a = mktime(pTime);
    printf("%s", ctime(&a));*/
    //нічого не працює з часом, time(NULL) не присвоюється

    printf("Enter name of first student\n>> ");
    scanf("%s", n);
    strcpy(students1->name, n);
    printf("Enter mark of first laptop\n>> ");
    scanf("%s", n);
    strcpy(students1->laptop->mark, n);

    printf("Enter name of second student\n>> ");
    scanf("%s", n);
    strcpy(students2->name, n);
    printf("Enter mark of first laptop\n>> ");
     scanf("%s", n);
    strcpy(students2->laptop->mark, n);

    //free(pTime);

}

void PrintStudent(struct Student * students1){
    printf("Name of student: %s", students1->name);
    //printf("Birthday of student: %s", ctime(students1->birthday));
    //printf("Release date of student: %s", ctime(students1->birthday));
    printf("Mark of laptop, student: %s", students1->laptop->mark);
}

void PrintLaptop(struct Laptop * laptop1){
    printf("Name of student: %s", laptop1->mark);
    //printf("Name of student: %s", ctime(laptop1->releasedate));
}
