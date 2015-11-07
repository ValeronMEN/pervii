#include <stdio.h>

double calc(int n, int m){
int i, j;
double resultIn=0, result=0;

for (i = 1; i<n; i++){
	for (j = 1; j<m; j++){
	resultIn += 1/j;
	}
result += i*resultIn;
}
return result;
}
