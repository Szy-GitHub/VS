#include<stdio.h>
#include<stdlib.h>

void printArr(int* data, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%-4d", data[i]);
    }
    printf("\n");
}

int getMax(int* data, int len)
{
    int max = data[0];
    for(int i = 0; i < len; i++)
    {
        if(data[i]>max)
        {
            max = data[i];
        }
    }
    return max;
}

void countSort(int* data, int len)
{
    int max = getMax(data, len);
    int* temp = (int*)malloc(sizeof(int)*(max+1));
    for(int i = 0; i < max+1; i++)
    {
        temp[i] = 0;
    }
    for(int i = 0; i < len; i++)
    {
        temp[data[i]]++;
    }
    int index = 0;
    for(int i = 0; i <= max; i++)
    {
        for(int j = 0; j < temp[i]; j++)
        {
            data[index] = i;
            index++;
        }
    }
    free(temp);
    temp = NULL;
}

int main()
{
    printf("First!\n");
    int arr[10] = {4, 2, 0, 5, 2, 9, 8, 2, 1, 6};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("Before Sort!\n");
    printArr(arr, len);
    countSort(arr, len);
    printf("After Sort!\n");
    printArr(arr, len);
    return 0;
}

