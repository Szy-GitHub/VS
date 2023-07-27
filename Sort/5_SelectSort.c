#include<stdio.h>

void PrintArr(int* data, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%-4d", data[i]);
    }
    printf("\n");
}

void SelectSort(int* data, int len)
{
    for(int i = 0; i < len; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < len; j++)
        {
            if(data[j] < data[minIndex])
            {
                minIndex = j;
            }
            
        }
        int temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;
    }
}

int main()
{
    printf("First\n");
    int arr[10] = {10, 3, 5, 2, 9, 8, 1, 4, 6, 7};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("Before Sort!\n");
    PrintArr(arr, len);
    SelectSort(arr, len);
    printf("After Sort!\n");
    PrintArr(arr, len);
    return 0;
}
