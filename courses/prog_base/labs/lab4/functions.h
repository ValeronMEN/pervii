struct Notes{
    char name;
    int freq;
    int oktava;
};

struct Melody{
    int index;
    char title[100];
    char composer[100];
    char playlist[100];
    char plot[200];
};

void printmelstruct(struct Melody *);
void printnotesstruct(struct Notes *);
void pianino (int, char, struct Notes *);
void pianino2 (int, char, struct Notes *);
void recordfile(int, struct Melody *);
char pianino3 (int, char, struct Notes *);

    /*COORD pos;
    color_elka; //34 39 42
    pos.X=5; pos.Y=4; SCCP;
    printf("*\n"); color_default;
    printf("    "); color_elka;
    printf("***\n"); color_default;
    printf("     "); color_elka;
    printf("*\n"); color_default;
    printf("   "); color_elka;
    printf("*****\n"); color_default;
    printf("     "); color_elka;
    printf("*\n"); color_default;
    printf("  "); color_elka;
    printf("*******\n"); color_default;
    SetConsoleTextAttribute(hConsole, 6);
    printf("     *\n");
    color_default;

    Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(417, 500);
    Beep(329, 500);
    Beep(247, 500);
    Beep(247, 500);
    Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(417, 500);
    Beep(497, 500);
    Sleep(500);
    Beep(497, 500);
    Beep(277, 500);
    Beep(277, 500);
    Beep(440, 500);
    Beep(440, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(329, 500);
    Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(417, 500);
    Beep(329, 500);

    printf("Merry Christmas to you!\n\n");
    Sleep(1000);
    */
