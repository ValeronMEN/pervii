#ifndef BLOG_H_INCLUDED
#define BLOG_H_INCLUDED

#define MAX_NAME_SIZE 50
#define MAX_USERS_SIZE 10
#define MAX_TEXT_SIZE 100
#define MAX_POSTS_SIZE 10
#define MAX_COMMENTS_SIZE 10

typedef struct valerooncom_s valerooncom_t;
typedef struct user_s user_t;
typedef struct comment_s comment_t;
typedef struct post_s post_t;

typedef enum valerooncom_status{
    OK,
    OVERFLOW,
    ID_ABS,
} valerooncom_status;

typedef enum user_status{
    USER_OK,
} user_status;

valerooncom_t * valerooncom_new();
void valerooncom_free();

user_t * user_new(int id, char * login, char * name, char * surname, int years, char * country, valerooncom_t * myNetwork);
void user_free(valerooncom_t * myNetwork, user_t * myUser);

user_t * user_get(valerooncom_t * myNetwork, int id);
void user_edit(int id, valerooncom_t * myNetwork, char * login, char * name, char * surname, int years, char * country);

comment_t * comment_new(user_t * userThatPost, post_t * myPost, char * text);
void comment_free(comment_t * myComment, post_t * myPost);

post_t * post_new(char * text, user_t * myUser);
void post_free(user_t * myUser, post_t * myPost);

void user_free();

#endif // BLOG_H_INCLUDED
