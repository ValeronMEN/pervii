//Музика. Ноти, музичні композиції, плейлісти.
//Можливість створювати нові компоиції, перейменовувати їх і видаляти.
//Створювати плейлісти з ними.
//Вивід списку плейлістів і списку композицій у обраному плейлісті.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "functions.h"

#define SCCP SetConsoleCursorPosition(hConsole, pos)
#define color_default SetConsoleTextAttribute(hConsole, 7)
#define color_disco SetConsoleTextAttribute(hConsole, 13)
#define color_elka SetConsoleTextAttribute(hConsole, 42)
#define color_error SetConsoleTextAttribute(hConsole, 12)
#define color_edit SetConsoleTextAttribute(hConsole, 11)
#define color_mem SetConsoleTextAttribute(hConsole, 9)
#define color_play SetConsoleTextAttribute(hConsole, 10)

int main()
{
    //welcomezone
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char name[100];

    printf("What is your name, mr. Nice Guy?\n>> ");
    gets(name);
    printf("\nHello, %s\n\n", name);

    //showstruct
    FILE *fp;
    char str[100];
    char answer[100];
    int amount, vsegda=0, i=0;

    fp = fopen("input.txt", "r");
    fscanf(fp, "%i", &amount);
    fgets(str, 100, fp);

    struct Melody * arr  = (struct Melody *) malloc (amount*sizeof(struct Melody));

    while(i<amount){
        fscanf(fp, "%i", &(arr[i].index));
        fgets(str, 100, fp);
        fgets(arr[i].title, 100, fp);
        fgets(arr[i].composer, 100, fp);
        fgets(arr[i].playlist, 100, fp);
        fgets(arr[i].plot, 200, fp);
        fgets(str, 100, fp);
        i++;
    }
    fclose(fp);
    i=0;

    printf("%s, do you want to see melody structures? (yes/no)\n>> ", name);
    gets(answer);
    while(strcmp(answer, "no")!=0){
        if (strcmp(answer, "yes")==0) {
            puts("");
            while(i<amount){
                printmelstruct(&(arr[i]));
                i++;
            }
            break;
        }
        printf("Invalid command. Try again.\n>> ");
        gets(answer);
    }

    //shownotes
    struct Notes mas[8];

    fp = fopen("notes.txt", "r");
    for(i=0; i<8; i++){
        fscanf(fp, "%c %i %i ", &(mas[i].name), &(mas[i].freq), &(mas[i].oktava));
    }
    fclose(fp);

    printf("%s, do you want to see notes structures? (yes/no)\n>> ", name);
    gets(answer);
    while(strcmp(answer, "no")!=0){
        if (strcmp(answer, "yes")==0) {
            puts("");
            for(i=0; i<8; i++){
               printnotesstruct(&(mas[i]));
            }
            break;
        }
        printf("Invalid answer. Try again.\n>> ");
        gets(answer);
    }

    //Piano Mode
    int length;
    char l, l2;
    char stroka[100] = {"C D E F G A B S"};

    printf("Enter time of notes playing [1..100000]\n>> ");
    while(vsegda==0){
        i = scanf("%i", &length);
        if (length>=1&&length<=100000){
            i=0; break;
        }
        else{
        printf("Invalid time. Try again.\n>> ");
        gets(str);
        }
    }
    puts("");
    Sleep(500);

    color_disco;
    printf("Piano Mode is on\n");
    color_default;
    printf("Press 'a'-'k' to play a note\nPress 'e' to exit the Piano Mode\nPress '1' to record track\nPress '2' to end track\nPress '3' to check last composition\nPress any button to pause\n");
    SetConsoleTextAttribute(hConsole, 92);
    printf("And now you can create music!\n");
    color_default;

    l = getch();
    while(l!='e'){
        if (l=='1'){
            color_disco;
            printf("Recording started...\n");
            fp = fopen("output.txt", "w");
            l2 = getch();
            while(l2!='2'){
               fprintf(fp, "%c ", pianino3(length, l2, &(mas[0])));
               l2 = getch();
            }
            fclose(fp);
            printf("Recording is finished\n");
            color_default;
        }
        if (l=='3'){
            fp = fopen("output.txt", "r");
            fgets(stroka, 100, fp);
            fclose(fp);
            color_disco;
            printf("The last track: ");
            SetConsoleTextAttribute(hConsole, 15);
            printf("%s\n", stroka);
            color_disco;
            printf("Press '4' to listen to music. Press any key to continue without listening\n");
            l2 = getch();
            if (l2=='4'){
                printf("Listening...\n");
                for(i=0; i<=(strlen(stroka)); i=i+2){
                    pianino2(length, stroka[i], &(mas[0]));
                }
                printf("Piano is active\n");
            }
            else{
                printf("Piano is active\n");
            }
            color_default;
        }
        pianino(length, l, &(mas[0]));
        l = getch();
    }
    color_disco;
    printf("Piano Mode is off\n");
    color_default;
    puts("");
    system("pause");

    //Melody Editor Mode
    int stind, j;
    char command[100];
    char editcommand[100];

    puts("");
    Sleep(500);
    color_mem;
    printf("Melody Editor Mode is on\n");
    color_default;
    printf("What do you want to do?\nEnter 'create' to create melody\nEnter 'edit' to edit melody\nEnter 'delete' to delete melody\nEnter 'exit' to exit the Melody Editor Mode\n>> ");
    gets(str);

    gets(command);
    while(strcmp(command, "exit")!=0){
        if (strcmp(command, "create")==0) {
            amount++;
            arr  = (struct Melody *) realloc (arr, (amount)*sizeof(struct Melody));
            color_error;
            printf("Warning: next step is using notes from Piano Mode. To change notes, please, relaunch program.\n");
            color_default;
            Sleep(1500);
            printf("Enter name of your song\n>> ");
            gets(answer);
            sprintf(&(arr[amount-1].title), "%s\n", answer);
            sprintf(&(arr[amount-1].composer), "%s\n", name);
            printf("Enter name of playlist\n>> ");
            gets(answer);
            sprintf(&(arr[amount-1].playlist), "%s\n", answer);
            sprintf(&(arr[amount-1].plot), "%s\n", stroka);
            (arr[amount-1].index) = amount;
            recordfile(amount, arr);
            color_mem;
            printf("Song is successfully created\n");
            color_default;
            printf("Enter next command\n>> ");
            gets(command);
            continue;
        }
        if (strcmp(command, "edit")==0){
            printf("Enter name of song\n>> ");
            gets(str);
            sprintf(str, "%s\n", str);
            stind=0;
            for (j=0; j<amount; j++){
                if(strcmp(&(arr[j].title), str)==0){
                    stind=j+1; break;
                }
            }
            if(stind==0){
               printf("Invalid name of song. Enter your command.\n>> ");
               gets(command);
               continue;
            }
            color_mem;
            puts("Name was found. Opening song...");
            color_edit;
            Sleep(500);
            printf("Edit Mode is on\n");
            color_default;
            printf("Enter 'rename' to rename\nEnter 'recomp' to change composer name\nEnter 'list' to change playlist\nEnter 'exit' to exit Edit Mode\n>> ");
            gets(editcommand);
            while(strcmp(editcommand, "exit")!=0){
                if (strcmp(editcommand, "rename")==0){
                    for(i=1; i<=amount; i++){
                        if (i==stind){
                            printf("Enter new name\n>> ");
                            gets(answer);
                            sprintf(&(arr[i-1].title), "%s\n", answer);
                            recordfile(amount, arr);
                            color_edit;
                            printf("Name is successfully changed\n");
                            color_default;
                        }
                    }
                    printf("Enter next command\n>> ");
                    gets(editcommand);
                    continue;
                }
                if (strcmp(editcommand, "list")==0){
                    for(i=1; i<=amount; i++){
                        if (i==stind){
                            printf("Enter name of playlist\n>> ");
                            gets(answer);
                            sprintf(&(arr[i-1].playlist), "%s\n", answer);
                            recordfile(amount, arr);
                            color_edit;
                            printf("Playlist of this song is successfully changed\n");
                            color_default;
                        }
                    }
                    printf("Enter next command\n>> ");
                    gets(editcommand);
                    continue;
                }
                if (strcmp(editcommand, "recomp")==0){
                    for(i=1; i<=amount; i++){
                        if (i==stind){
                            printf("Enter new composer\n>> ");
                            gets(answer);
                            sprintf(&(arr[i-1].composer), "%s\n", answer);
                            recordfile(amount, arr);
                            color_edit;
                            printf("Composer is successfully changed\n");
                            color_default;
                        }
                    }
                    printf("Enter next command\n>> ");
                    gets(editcommand);
                    continue;
                }
                printf("Invalid command. Try again.\n>> ");
                gets(editcommand);
            }
            color_edit;
            printf("Edit Mode is off\n");
            Sleep(500);
            color_mem;
            puts("Returning to Melody Editor Mode...");
            Sleep(500);
            color_default;
            printf("Enter next command\n>> ");
            gets(command);
            continue;
        }
        if (strcmp(command, "delete")==0){
            printf("Enter name of song to delete\n>> ");
            gets(str);
            sprintf(str, "%s\n", str);
            stind=0;
            for (j=0; j<amount; j++){
                if(strcmp(&(arr[j].title), str)==0){
                    stind=j+1; break;
                }
            }
            if(stind==0){
               printf("Invalid name of song. Enter your command.\n>> ");
               gets(command);
               continue;
            }
            for(i=0; i<amount; i++){
                if(i>(stind-1)){
                    arr[i-1]=arr[i];
                    arr[i-1].index=i;
                }
            }
            amount--;
            recordfile(amount, arr);
            color_mem;
            printf("Melody is successfully deleted\n");
            color_default;
            printf("Enter next command\n>> ");
            gets(command);
            continue;
        }
        printf("Invalid command. Try again.\n>> ");
        gets(command);
    }
    color_mem;
    printf("Melody Editor Mode is off\n");
    color_default;
    Sleep(500);

    //showstruct?
    i=0;
    printf("\n%s, do you want to see melody structures again? (yes/no)\n>> ", name);
    gets(answer);
    while(strcmp(answer, "no")!=0){
        if (strcmp(answer, "yes")==0) {
            puts("");
            while(i<amount){
                printmelstruct(&(arr[i]));
                i++;
            }
            break;
        }
        printf("Invalid command. Try again.\n>> ");
        gets(answer);
    }
    system("pause");

    //playlists
    char * playlists[amount];
    int number;

    Sleep(500);
    color_play;
    printf("\nPlayer Mode is on\n");
    color_default;
    printf("Welcome to Player Mode!\nEnter 'playlists' to check all playlists\nEnter 'playlist' to check current playlist and listen it\nEnter 'play' to listen to current song\nEnter 'exit' to exit Playlists Editor Mode\n>> ");
    gets(command);
    while(strcmp(command, "exit")!=0){
        if(strcmp(command, "playlists")==0){
            puts("There are all playlists:");
            number=1;
            for(i=0; i<amount; i++){
                stind=0;
                *(playlists+i)=arr[i].playlist;
                for(j=0; j<i; j++){
                    if (strcmp(*(playlists+i), *(playlists+j))==0) stind=1;
                }
            if(stind==0){
                color_play;
                printf("%i. ", number);
                number++;
                printf("%s", *(playlists+i));
                color_default;
            }
            }
            printf("Enter your next command\n>> ");
            gets(command);
            continue;
        }
        if(strcmp(command, "playlist")==0){
            number=1;
            printf("Enter name of playlist\n>> ");
            gets(str);
            sprintf(str, "%s\n", str);
            stind=0;
            for (j=0; j<amount; j++){
                if(strcmp(&(arr[j].playlist), str)==0){
                    stind=1;
                }
            }
            if(stind==0){
            printf("Invalid name of playlist. Enter your command.\n>> ");
            gets(command);
            continue;
            }
            color_play;
            puts("Playlist was found");
            Sleep(500);
            puts("Listening...");
            Sleep(500);
            for (j=0; j<amount; j++){
                if(strcmp(&(arr[j].playlist), str)==0){
                    printf("%i. %s", number, arr[j].title);
                    number++;
                    sprintf(stroka, "%s", arr[j].plot);
                    for(i=0; i<=(strlen(stroka)); i=i+2){
                        pianino2(length, stroka[i], &(mas[0]));
                    }
                    Sleep(1000);
                }
            }
            color_default;
            printf("Enter your next command\n>> ");
            gets(command);
            continue;
        }
        if(strcmp(command, "play")==0){
            printf("Enter name of song to play\n>> ");
            gets(str);
            sprintf(stroka, "%s\n", str);
            stind=0;
            for (j=0; j<amount; j++){
                if(strcmp(&(arr[j].title), stroka)==0){
                    stind=1;
                    sprintf(stroka, "%s", arr[j].plot);
                    break;
                }
            }
            if(stind==0){
            printf("Invalid name of playlist. Enter your command.\n>> ");
            gets(command);
            continue;
            }
            color_play;
            printf("Listening...");
            Sleep(500);
            printf(" %s\n", str);
            for(i=0; i<=(strlen(stroka)); i=i+2){
                pianino2(length, stroka[i], &(mas[0]));
            }
            color_default;
            printf("Enter your next command\n>> ");
            gets(command);
            continue;
        }
        printf("Invalid command. Try again.\n>> ");
        gets(command);
    }
    color_play;
    printf("Player Mode is off\n");
    color_default;

    Sleep(500);
    free(arr);
    printf("\nGoodbye, %s!\n", name);
    return 0;
}
