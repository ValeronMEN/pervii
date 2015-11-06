#include <stdlib.h>
#include <math.h>

void fillRand2(int arr[], int size){
    int i;
for (i = 0; i < size; i++)
{
    arr[i]=rand() % 511 - 255;
}
}

int checkRand2(int arr[], int size){
    int j, result;
    for (j=size-1; j>-1; j--){
        if (arr[j]<(-255)){
        result = 0;
        return 0; break;
        }
        if (arr[j]>255){
        result = 0;
        return 0; break;
        }
        if (arr[j]>=(-255) && arr[j]<=255){
    result = 1;
    }
    }
    if (result==1)
        return 1;
}

float meanValue(int arr[], int size){
    int i, sum;
    float ser;
    sum = 0;
for (i=0; i<size; i++){
    sum = sum + arr[i];
    }
    ser = sum/size;
    return ser;
}

int minValue(int arr[], int size){
    int i, min;
    min = arr[0];
for (i=0; i<size; i++){
if (min>arr[i]){
    min = arr[i];
}
if (min<=arr[i]){
    min = min;
}
}
return min;
}

int meanIndex(int arr[], int size){
    int i, n, sum;
    float ser;
    int min, j, k;
    sum = 0;
    n = 0;
for (i=0; i<size; i++){
    sum = sum + arr[i];
    n=n+1;
    }
    ser = sum/n;
    min = arr[0];
    k=0;
    for (j=0; j<size; j++){
        if ((fabs(ser-arr[j]))<(fabs(ser-min))){
           min = arr[j];
           k=j;
        }
        if ((fabs(ser-arr[j]))>=(fabs(ser-min))){
           min = min;
        }
    }
    return k;
}

int minIndex(int arr[], int size){
int i, min, k;
    min = arr[0];
    k=0;
     for (i=0; i<size; i++){
      if (min>arr[i]){
          min=arr[i];
          k=i;
      }
      if (min<=arr[i]){
          min = min;
      }
     }
return k;
}

int maxOccurance(int arr[], int size){
int j, i, kolvo, max, zn, x, y, l;
x=0;
for (y=size-1; y>-1; y--){
    if (arr[size-1]==arr[y]){
        x=x+1;
    }
}
max = x;
zn=arr[size-1];
kolvo = 0;
for (j=size-1; j>-1; j--){
        for (i=size-1; i>-1; i--){
            if (arr[j]==arr[i])
            kolvo = kolvo + 1;
        }
        if (max<kolvo){
            max=kolvo;
            zn=arr[j];
        }
        if (max>kolvo){
            max=max;
            zn=zn;
        }
         if (max=kolvo){
            if (zn<arr[j]){
                zn=arr[j];
            }
            if (zn>arr[j]){
                zn=zn;
            }
         }
        kolvo=0;
    }
    return zn;
}

int diff(int arr1[], int arr2[], int res[], int size){
int i, j, result;
for (i=0; i<size; i++){
    res[i] = arr1[i]-arr2[i];
}
result = 1;
for (j=0; j<size; j++){
    if (res[j]!=0){
    result = 0;
}
}
return result;
}

void sub(int arr1[], int arr2[], int res[], int size){
int i;
for (i=0; i<size; i++){
    res[i] = arr1[i]-arr2[i];
}
}

int lt(int arr1[], int arr2[], int size){
int i, result;
result = 1;
for (i=0; i<size; i++){
    if (arr1[i]>arr2[i]){
        result = 0;
    }
}
return result;
}

void land(int arr1[], int arr2[], int res[], int size){
int i;
for (i=0; i<size; i++){
    res[i] = arr1[i]&arr2[i];
}
}


int main(){
int i, x, min, ind, ind2, chas, pr, pr2, riz, riz2;
float ser;
int v=4;

int myMatrix[4] =
{
1,2,3,4
};

int myMatrix2[4] =
{
1,2,3,4
};

int myMatrix3[4] =
{
1,2,3,4
};

int myMatrix4[4] =
{
0,0,0,0
};

int log1[4] =
{
0,1,0,1
};

int log2[4] =
{
1,1,0,0
};

puts("Proizvolnaia matriza");
srand(time(NULL));
fillRand2(myMatrix, v);
for(i = 0; i<4; i++){
            printf("%d\n",myMatrix[i]);
    }
puts(" \n");

x = checkRand2(myMatrix, v);
printf("Vse elementi ot -255 do 255?\n %d\n", x);
puts(" \n");

ser = meanValue(myMatrix, v);
printf("Srednee arifmeticheskoe\n %f\n", ser);
puts(" \n");

min = minValue(myMatrix, v);
printf("Minimalnii element masiva\n %d\n", min);
puts(" \n");

ind = meanIndex(myMatrix, v);
printf("index pervogo element, nablizhenii do ser ar\n %d\n", ind);
puts(" \n");

ind2 = minIndex(myMatrix, v);
printf("index pervogo minimalnogo\n %d\n", ind2);
puts(" \n");

chas = maxOccurance(myMatrix, v);
printf("samii chastii element (bolshii)\n %d\n", chas);
puts(" \n");

pr = diff(myMatrix, myMatrix2 , myMatrix3, v);
printf("vse raznizi = 0?\n %d\n", pr);
puts(" \n");

pr2 = diff(myMatrix, myMatrix, myMatrix3, v);
printf("vse raznizi = 0? (sdelano narochno)\n %d\n", pr2);
puts(" \n");

puts("Raznica 2-x matriz");
sub(myMatrix, myMatrix2, myMatrix3, v);
for(i = 0; i<4; i++){
            printf("%d\n",myMatrix3[i]);
    }
puts(" \n");

riz = lt(myMatrix, myMatrix2, v);
printf("vse menshe?\n %d\n", riz);
puts(" \n");

riz2 = lt(myMatrix4, myMatrix2, v);
printf("vse menshe?(narochno)\n %d\n", riz2);
puts(" \n");

puts("logicheskii AND");
land(log1, log2, myMatrix3, v);
for(i = 0; i<4; i++){
            printf("%d\n",myMatrix3[i]);
    }
puts(" \n");

getchar();
return 0;
}
