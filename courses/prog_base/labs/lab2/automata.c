int run(int moves[], int movesLen, int res[], int resLen){
enum stani{a0=0, a1, a2, a3};
int commands[4][102];
int perehod[4][102];
int vvod, stan, i, j, k, n, pr, cm;

    /*
    repeat - 11;
    break - 55;
    continue - 22;
    pop - 44;
    */

    commands[a0][2]=1;
    commands[a0][6]=11;
    commands[a0][11]=8;
    commands[a0][101]=55;

    commands[a1][2]=44;
    commands[a1][6]=2;
    commands[a1][11]=55;
    commands[a1][101]=5;

    commands[a2][2]=6;
    commands[a2][6]=22;
    commands[a2][11]=3;
    commands[a2][101]=44;

    commands[a3][2]=55;
    commands[a3][6]=7;
    commands[a3][11]=55;
    commands[a3][101]=4;

    perehod[a0][2]=1;
    perehod[a0][6]=1;
    perehod[a0][11]=0;

    perehod[a1][2]=3;
    perehod[a1][6]=2;
    perehod[a1][101]=1;

    perehod[a2][2]=2;
    perehod[a2][6]=1;
    perehod[a2][11]=3;
    perehod[a2][101]=0;

    perehod[a3][6]=3;
    perehod[a3][101]=0;

    /* 5 - break */

    commands[a0][5]=55;
    commands[a1][5]=55;
    commands[a2][5]=55;
    commands[a3][5]=55;

stan=0;
j=0;

     for (i=0; i<movesLen; i++){
            metkaS:
        vvod = moves[i];
        if (vvod!=2&&vvod!=6&&vvod!=11&&vvod!=101){
            vvod = 5; /* 5 - random */
        }
        cm = commands[stan][vvod];
        switch (cm){
            case 1: res[j]=1; j=j+1;
            pr = perehod[stan][vvod];
            switch (pr)
            {
                case 0: stan = 0; break;
                case 1: stan = 1; break;
                case 2: stan = 2; break;
                case 3: stan = 3; break;
            }
            break;
            case 4: res[j]=4; j=j+1;
            pr = perehod[stan][vvod];
            switch (pr)
            {
                case 0: stan = 0; break;
                case 1: stan = 1; break;
                case 2: stan = 2; break;
                case 3: stan = 3; break;
            }
            break;
            case 8: res[j]=8; j=j+1;
            pr = perehod[stan][vvod];
            switch (pr)
            {
                case 0: stan = 0; break;
                case 1: stan = 1; break;
                case 2: stan = 2; break;
                case 3: stan = 3; break;
            }
            break;
            case 2: res[j]=2; j=j+1;
            pr = perehod[stan][vvod];
            switch (pr)
            {
                case 0: stan = 0; break;
                case 1: stan = 1; break;
                case 2: stan = 2; break;
                case 3: stan = 3; break;
            }
            break;
            case 5: res[j]=5; j=j+1;
            pr = perehod[stan][vvod];
            switch (pr)
            {
                case 0: stan = 0; break;
                case 1: stan = 1; break;
                case 2: stan = 2; break;
                case 3: stan = 3; break;
            }
            break;
            case 6: res[j]=6; j=j+1;
            pr = perehod[stan][vvod];
            switch (pr)
            {
                case 0: stan = 0; break;
                case 1: stan = 1; break;
                case 2: stan = 2; break;
                case 3: stan = 3; break;
            }
            break;
            case 3: res[j]=3; j=j+1;
            pr = perehod[stan][vvod];
            switch (pr)
            {
                case 0: stan = 0; break;
                case 1: stan = 1; break;
                case 2: stan = 2; break;
                case 3: stan = 3; break;
            }
            break;
            case 7: res[j]=7; j=j+1;
            pr = perehod[stan][vvod];
            switch (pr)
            {
                case 0: stan = 0; break;
                case 1: stan = 1; break;
                case 2: stan = 2; break;
                case 3: stan = 3; break;
            }
            break;
            case 55: goto metka1; break;
            case 22:
                pr = perehod[stan][vvod];
            switch (pr)
            {
                case 0: stan = 0;  break;
                case 1: stan = 1;  break;
                case 2: stan = 2;  break;
                case 3: stan = 3;  break;
            }
            break;
            case 11: pr = perehod[stan][vvod];
            switch (pr)
            {
                case 0: stan = 0; break;
                case 1: stan = 1; break;
                case 2: stan = 2; break;
                case 3: stan = 3; break;
            }
            goto metkaS; break;
            case 44:
                if (j==0){
                    continue;
                }
                            res[j-1]=0;
                            j = j-1;

            pr = perehod[stan][vvod];
            switch (pr)
            {
                case 0: stan = 0; break;
                case 1: stan = 1; break;
                case 2: stan = 2; break;
                case 3: stan = 3; break;
            }
            break;
        }
     }
metka1:
    n = 0;
    for (k=0; k<resLen; k++){
        if (res[k]!=0){
            n = n+1;
        }
    }
    return n;
}
