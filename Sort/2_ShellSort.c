#include<stdio.h>

void PrintArr(int *data, int len)
{
	for(int i = 0; i < len; i++)
	{
		printf("%3d", data[i]);
	}
	printf("\n");
}

void ShellSort(int* data, int len)
{
    int i, j, gap;
    for(gap = len / 2; gap >= 1; gap /= 2)
    {
        for(i = gap; i < len; i++)
        {
            int temp = data[i];
            for(j = i - gap; j >= 0 && data[j] > temp; j -= gap)
            {
                data[j+gap] = data[j];
            }
            data[j+gap] = temp;
        }
    }
}

int main()
{
	printf("First!\n");
	int arr[10] = {1,9, 6, 8, 10, 5, 3, 2, 4, 7};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("Before Sort!\n");
	PrintArr(arr, len);
    ShellSort(arr, len);
	printf("After Sort!\n");
	PrintArr(arr, len);
	printf("\n");
	return  0;

}