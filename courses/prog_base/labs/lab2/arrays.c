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
           if (arr[j]<(-255)&&arr[j]>255){
           return 0;
           }
    }
    return 1;
}

float meanValue(int arr[], int size){
    int i, sum=0;
    float ser;
for (i=0; i<size; i++){
    sum += arr[i];
    }
    return sum/size;
}

int minValue(int arr[], int size){
    int i, min;
    min = arr[0];
for (i=0; i<size; i++){
if (min>arr[i]){
    min = arr[i];
}
}
return min;
}

int meanIndex(int arr[], int size){
    int i, n = 0, sum = 0, min, j, k=0;
    float ser;
for (i=0; i<size; i++){
    sum +=arr[i];
    n++;
    }
ser = sum/n;
min = arr[0];
for (j=0; j<size; j++){
    if ((fabs(ser-arr[j]))<(fabs(ser-min))){
        min = arr[j];
        k=j;
    }
}
return k;
}

int minIndex(int arr[], int size){
int i, min, k=0;
    min = arr[0];
     for (i=0; i<size; i++){
      if (min>arr[i]){
          min=arr[i];
          k=i;
      }
     }
return k;
}

int maxOccurance(int arr[], int size){
int j, i, kolvo=0, max, zn, x=0, y, l;
for (y=size-1; y>-1; y--){
    if (arr[size-1]==arr[y]){
        x++;
    }
}
max = x;
zn=arr[size-1];
for (j=size-1; j>-1; j--){
        for (i=size-1; i>-1; i--){
            if (arr[j]==arr[i])
            kolvo++;
        }
        if (max<kolvo){
            max=kolvo;
            zn=arr[j];
        }
         if (max==kolvo&&zn<arr[j]){
            zn=arr[j];
         }
        kolvo=0;
    }
    return zn;
}

int diff(int arr1[], int arr2[], int res[], int size){
int i;
for (i=0; i<size; i++){
    res[i] = arr1[i]-arr2[i];
        if (res[i]!=0){
        return 0;
        }
     }
return 1;
}

void sub(int arr1[], int arr2[], int res[], int size){
int i;
for (i=0; i<size; i++){
    res[i] = arr1[i]-arr2[i];
}
}

int lt(int arr1[], int arr2[], int size){
int i;
for (i=0; i<size; i++){
    if (arr1[i]>arr2[i]){
        return 0;
    }
}
return 1;
}

void land(int arr1[], int arr2[], int res[], int size){
int i;
for (i=0; i<size; i++){
    res[i] = arr1[i]&arr2[i];
}
}
