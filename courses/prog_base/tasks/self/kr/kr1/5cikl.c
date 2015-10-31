// Babenko V, KP-51 v-11 5

#include <math.h>

void main(void){
    int size, s;
    int a[7] =
{
1,2,3,4, 15,0, -3
};
size=7;
s = sub(a, size);
}

void sub(int myMatrix[], int n){
    int i, min;

for (i = 0; i < n; i++)
{
    if (myMatrix[i]%3==0){
        min = myMatrix[i]; break;
    }
}

for (i = 0; i < n; i++)
{
    if (myMatrix[i]%3==0){
        printf("%i ", myMatrix[i]);
        if (min>myMatrix[i]){
            min = myMatrix[i];
        }
        if (min<=myMatrix[i]){
            min=min;
        }
    }
}

puts("\n");
printf("Naimenshe sered chisel, sho diliatsa nacilo na 3: %i", min);
return 1;
}
