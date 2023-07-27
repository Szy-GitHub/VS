#include<stdio.h>
#include<stdlib.h>

void printArr(int* data, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%-5d",data[i]);
    }
    printf("\n");
}

typedef struct node
{
    int data;
    struct node* next; 
}node;

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

void insert_node(node** bucket, int data)
{
    node* p = (node*)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    if(*bucket == NULL)
    {
        *bucket = p;
    }
    else
    {
        node *pre = NULL;
        node *cur = *bucket;
        while(cur != NULL && cur->data <= data)
        {
            pre = cur;
            cur = cur->next;
        }
        if(pre == NULL)
        {
            *bucket = p;
            p->next = cur;
        }
        else
        {
            pre->next = p;
            p->next = cur;
        }
    }
}

void bucketSort(int* data, int len)
{
    node** b = (node**)calloc(10, sizeof(node*));
    int i, j, m;
    int k = maxBit(data, len);
    for(int i = 0; i < len; i++)
    {
        m = data[i];
        for(j = k; j > 1; j--)
        {
            m = m / 10;
        }
        // 插入排序
        insert_node(&b[m],data[i]);
    }
    
    node* p;
    // 遍历每个桶
    for(i = 0, j = 0; i < 10 && j < len; i++)
    {
        if(b[i] != NULL)
        {
            p = b[i];
            // 倒出每个桶中的数据
            while(p != NULL)
            {
                data[j] = p->data;
                j++;
                p = p->next;
            }
        }
    }
    for(i = 0; i < 10; i++)
    {
        while(b[i] != NULL)
        {
            p = b[i];
            b[i] = p->next;
            free(p);
        }
    }
    free(b);

}

int main()
{
    printf("First!\n");
    int arr[10] = {11,123,999,543,456,765,678,987,890,234};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("Before Sort!\n");
    printArr(arr,len);
    bucketSort(arr, len);
    printf("After Sort!\n");
    printArr(arr, len);
    return 0;
}
