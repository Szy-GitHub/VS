#include<stdio.h>

void PrintArr(int* data, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%-3d",data[i]);
    }
    printf("\n");
}

int Partition(int* data, int low, int high)
{
    int pivot = data[low];
    while(low < high)
    {
        while(low < high && data[high] >= pivot)
            high--;
        data[low] = data[high];
        while(low < high && data[low] <= pivot)
            low++;
        data[high] = data[low];
    }
    data[low] = pivot;
    return low;
}

void QuickSort(int* data, int low, int high)
{
    if(low < high)
    {
        int pivotpos = Partition(data, low, high);
        QuickSort(data, low, pivotpos-1);
        QuickSort(data, pivotpos+1, high);
    }
}

int main()
{
    printf("First\n");
    int arr[10] = {3, 4, 6, 1, 9, 2, 8, 10, 7, 5};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("Before Sort!\n");
    PrintArr(arr, len);
    QuickSort(arr, 0, len - 1);
    printf("After Sort!\n");
    PrintArr(arr, len);
    return 0;
}



