#include <stdio.h>

double calc(int n, int m){
    int i, j;
    int r, rsum, r2, rsum2;
    for (i=1; i<(n+1); i++){
        for (j=1; j<(m+1); j++){
            r=1/(j);
            rsum=rsum+r;
        }
        r2=rsum*i;
        rsum2=rsum2+r2;
    }
    return rsum2;
}

double calc(int, int);

int main() {
	int a=1, b=1;
	double result;

	result = calc(a, b);

	printf("%f", result);
	return 0;
}
