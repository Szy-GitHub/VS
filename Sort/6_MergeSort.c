#include<stdio.h>
#include<stdlib.h>

void PrintArr(int* data, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%-3d",data[i]);
    }    
    printf("\n");
}

void MergeArr(int* data, int low, int mid, int high)
{
    int *tempArr = (int*)malloc(sizeof(int)*(high-low+1));
    int i = low, j = mid + 1, k = 0;
    while(i <= mid && j <= high)
    {
        if(data[i] < data[j])
        {
            tempArr[k] = data[i];
            i++;
        }
        else
        {
            tempArr[k] = data[j];
            j++;
        }
        k++;
    }
    while(i <= mid)
    {
        tempArr[k++] = data[i++];
    }
    while(j <= high)
    {
        tempArr[k++] = data[j++];
    }
    i = low;
    for(int tempk = 0; tempk < k && i <= high; tempk++)
    {
        data[i] = tempArr[tempk];
        i++;
    }
    free(tempArr);
    tempArr = NULL;
}

void SortArr(int* data, int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        SortArr(data, low, mid);
        SortArr(data, mid+1, high);
        MergeArr(data, low, mid, high);
    }
}

int main()
{
    printf("First!\n");
    int arr[] = {3, 5, 2, 10, 9, 1, 8, 4, 7, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("Before Sort!\n");
    PrintArr(arr, len);
    SortArr(arr, 0, len - 1);
    printf("After Sort!\n");
    PrintArr(arr, len);
    return 0;
}
