#include<stdio.h>

void PrintArr(int* data, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%3d", data[i]);
    }
    printf("\n");
}

void BubbleSort(int* data, int len)
{
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 0; j < len - i - 1; j++)
        {
            if(data[j] > data[j+1])
            {
                int temp = data[j+1];
                data[j+1] = data[j];
                data[j] = temp;
            }
        }
    }
}

int main()
{
    printf("First!\n");
    int arr[10] = {3, 4, 6, 1, 9, 2, 5, 7, 10, 8};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("Before Sort!\n");
    PrintArr(arr, len);
    BubbleSort(arr, len);
    printf("After Sort!\n");
    PrintArr(arr, len);
    return 0;
}