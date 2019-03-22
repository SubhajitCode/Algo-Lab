#include<stdio.h>
 int range=10;
void printArray(int array[],char string[],int size)
{
    int i;
    printf("-----------------------------printing %s starts--------------------------\n",string);
    for(i=0;i<size;i++)
        printf("%d ,",array[i]);
    printf("\n");
    printf("-----------------------------printing %s ends----------------------------\n",string);
}
int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    int i;
    for (i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 

void countSort(int arr[], int n, int exp) 
{ 
    int outPut[n];
    int i, count[10] = {0}; 
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++;  
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
    for (i = n - 1; i >= 0; i--) 
    { 
        outPut[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    for (i = 0; i < n; i++) 
        arr[i] = outPut[i]; 
} 
void radixsort(int arr[], int n) 
{  
    int m = getMax(arr, n),exp; 
    for (exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 

int main()
{
    int size=8;
    int array[]={1,4,7,8,1,2,4,6};
     printArray(array,"Input",size);
    radixsort(array,size);
    printArray(array,"Output",size);
return 0;
}