#include<stdio.h>
void printArray(int array[],char string[],int size)
{
    int i;
    printf("-----------------------------printing %s starts--------------------------\n",string);
    for(i=0;i<size;i++)
        printf("%d ,",array[i]);
    printf("\n");
    printf("-----------------------------printing %s ends----------------------------\n",string);
}

void countArray(int array[],int count[],int range,int size)
{
    printArray(array,"Input",size);
    int i;
    for(i=0;i<=range;i++)
        count[i]=0;
    for(i=0;i<size;i++)
    {
        count[array[i]]=count[array[i]]+1;
    }
    for(i = 1; i <= range; i++)
    {
     count[i]=count[i]+count[i-1];   
    }
    
}
void countSort(int array[],int outPut[],int range,int size)
{
    int count[range+1];
    countArray(array,count,range,size);
    printArray(count," Count ",range+1);
    int i=0;
    while(i<size)
    {
        int j= array[i];
        int k=count[j];
        if(k!=0)
        {
            outPut[k-1]=j;
            k--;
            count[j]--;
            i++;
        }
        
    } 

}

int main()
{
    int range=10;
    int size=8;
    int array[]={1,4,7,8,1,2,4,6};
    int outPut[size];
    countSort(array,outPut,range,size);
    printArray(outPut,"Output",size);
return 0;
}