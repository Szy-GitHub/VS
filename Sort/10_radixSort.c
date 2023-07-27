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
// 求出数组中最大数的位数
int maxBit(int* data, int len)
{
    int max = data[0];
    for(int i = 0; i < len; i++)
    {
        if(data[i]>max)
        {
            max = data[i];
        }
    }
    int p = 0;
    while(max > 0)
    {
        p++;
        max /= 10;
    }
    return p;
}
// 取出所给数字的第d位数字
int getNum(int num, int d)
{
    int p = 1;
    while(d-1 > 0)
    {
        p *= 10;
        d--;
    }
    return num/p%10;
}

void radixSort(int* data, int len)
{
    int* bucket = (int*)malloc(sizeof(int)*len);
    for(int d = 1; d <= maxBit(data,len); d++)
    {
        // 计数器清零
        int count[10] = {0};
        // 统计各个桶中的个数
        for(int i = 0; i < len; i++)
        {
            count[getNum(data[i], d)]++;
        }
        // 每个数应该放入bucket中的位置
        for(int  i = 1; i < 10; i++)
        {
            count[i] += count[i-1];
        }

        for(int i = len - 1; i >= 0; i--)
        {
            int k = getNum(data[i], d);
            bucket[count[k]-1] = data[i];
            count[k]--;
        }

        for(int j = 0; j < len; j++)
        {
            data[j] = bucket[j];
        }
    }
    free(bucket);
}

int main()
{
    printf("First!\n");
    int arr[10] = {2, 45, 98, 823, 318, 601, 928, 189, 43, 342};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("Before Sort!\n");
    printArr(arr, len);
    radixSort(arr, len);
    printf("After Sort!\n");
    printArr(arr, len);
    return 0;
}

