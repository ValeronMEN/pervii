#ifndef BLOG_H_INCLUDED
#define BLOG_H_INCLUDED

#define MAX_NAME_SIZE 50
#define MAX_USERS_SIZE 10

typedef struct valerooncom_s valerooncom_t;
typedef struct user_s user_t;

typedef enum valerooncom_status{
    OK,
} valerooncom_status;

typedef enum user_status{
    USER_OK,
} user_status;

valerooncom_t * valerooncom_new();
void valerooncom_free();

user_t * user_new(int id, char * login, char * name, char * surname, int years, char * country);
void user_free();

#endif // BLOG_H_INCLUDED
