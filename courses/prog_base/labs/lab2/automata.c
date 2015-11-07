int run(int moves[], int movesLen, int res[], int resLen){
enum stani{a0=0, a1, a2, a3};
int commands[4][102];
int perehod[4][102];
int vvod, stan=0, i, j=0, k, n=0, pr, cm;

    /* repeat - 11; break - 55; continue - 22; pop - 44; */

    commands[a0][2]=1;     perehod[a0][2]=1;
    commands[a0][6]=11;    perehod[a0][6]=1;
    commands[a0][11]=8;    perehod[a0][11]=0;
    commands[a0][101]=55;

    commands[a1][2]=44;    perehod[a1][2]=3;
    commands[a1][6]=2;     perehod[a1][6]=2;
    commands[a1][11]=55;
    commands[a1][101]=5;   perehod[a1][101]=1;

    commands[a2][2]=6;     perehod[a2][2]=2;
    commands[a2][6]=22;    perehod[a2][6]=1;
    commands[a2][11]=3;    perehod[a2][11]=3;
    commands[a2][101]=44;  perehod[a2][101]=0;

    commands[a3][2]=55;
    commands[a3][6]=7;     perehod[a3][6]=3;
    commands[a3][11]=55;
    commands[a3][101]=4;   perehod[a3][101]=0;

     for (i=0; i<movesLen; i++){
        vvod = moves[i];
        if (vvod!=2&&vvod!=6&&vvod!=11&&vvod!=101){
            for (k=0; k<resLen; k++){
            if (res[k]!=0){
            n++;
            }
            }
            return n;
        }
        cm = commands[stan][vvod];
        switch (cm){
            case 55: /* break */
            for (k=0; k<resLen; k++){
            if (res[k]!=0){
            n++;
            }
            }
            return n; break;
            case 22: /* continue */
                pr = perehod[stan][vvod];
                stan = pr; break;
            case 11: pr = perehod[stan][vvod];
                stan = pr;
                i=i-1; break;
            case 44: /* pop */
                if (j==0){
                    continue;
                }
                res[j-1]=0;
                j--;
                pr = perehod[stan][vvod];
                stan = pr; break;
            default: res[j]=cm; j++;
                pr = perehod[stan][vvod];
                stan = pr; break;
        }
     }
    for (k=0; k<resLen; k++){
        if (res[k]!=0){
            n++;
        }
    }
    return n;
}
