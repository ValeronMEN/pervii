#include <winsock2.h>
#include <windows.h>

#define MAXBUFLEN 20480
#define NO_FLAGS_SET 0

char * function_request(SOCKET recvSocket, const char request [], char buffer [], int maxLen){
    send(recvSocket, request, strlen(request), 0);

    int numrcv = 0;
    int status = 0;
    int i;
    for (i=0; i<MAXBUFLEN; i++){
        buffer[i] = 0;
    }

    numrcv = recv(recvSocket, buffer, MAXBUFLEN, NO_FLAGS_SET);
    if (numrcv == SOCKET_ERROR)
    {
        printf("ERROR: recvfrom unsuccessful\r\n");
        status = closesocket(recvSocket);
        if(status == SOCKET_ERROR)
			printf("ERROR: closesocket unsuccessful\r\n");
        status = WSACleanup();
        if (status == SOCKET_ERROR)
			printf("ERROR: WSACleanup unsuccessful\r\n");
        system("pause");
        return(1);
    }

    printf("%s\r\n", buffer);

    return buffer;
}

char * function_secret(char * buffer_p){
    char *p;
    char del[] = "=";
    p = strtok(buffer_p, del);
    p = strtok(NULL, del);
    p = strtok(NULL, del);

    printf("\nSecret word is '%s'\n\n", p);
    return p;
}

void function_list(char * list, char * buffer_p){
    int i = 0;
    int j = 0;
    while (j<6){ //6 - an amount of strings of information about server
        if (buffer_p[i++]=='\n'){
            j++;
        }
    }

    strcpy(list, buffer_p+i);
    return;
}

char * function_nameOfMax(char * list, int size, char * strmax){
    int max=0;
    int a;
    char str[size];
    char del[] = " \n";
    char * p = strtok(list, del);
    while(p!=NULL){
        printf("Surname is %s\n", p);
        strcpy(str, p);
        p = strtok(NULL, del);
        a = atoi(p);
        printf("  Mark is %i\n", a);
        p = strtok(NULL, del);
        if (max<a){
            max = a;
            strcpy(strmax, str);
        }
    }

    printf("\nSurname with maximum mark is %s\n\n", strmax);
}
