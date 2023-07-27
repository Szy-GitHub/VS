#include<stdio.h>

void mySwap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArr(int* data, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%-4d", data[i]);
    }
    printf("\n");
}

void maxHeap_down(int* data, int len, int index)
{
    int left = 2*index + 1;
    int right = 2*index + 2;
    int maxIdx = index;
    if(left < len && data[left] > data[maxIdx])
        maxIdx = left;
    if(right < len && data[right] > data[maxIdx])
        maxIdx = right;
    if(maxIdx != index)
    {
        mySwap(&data[maxIdx], &data[index]);
        maxHeap_down(data, len, maxIdx);
    }
}

void heapSort(int* data, int len)
{
    for(int i = len / 2 - 1; i >= 0; i--)
    {
        maxHeap_down(data, len, i);
    }
    for(int i = len - 1; i >= 1; i--)
    {
        mySwap(&data[0],&data[i]);
        maxHeap_down(data, i, 0);
    }
}

int main()
{
    printf("First!\n");
    int arr[] = {3, 10, 4, 9, 1, 5, 8, 7, 2, 6};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("Before Sort!\n");
    printArr(arr, len);
    heapSort(arr, len);
    printf("After Sort!\n");
    printArr(arr, len);
    return 0;
}
