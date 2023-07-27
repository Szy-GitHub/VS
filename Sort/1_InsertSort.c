#include<stdio.h>
void PrintArr(int *data, int len)
{
	for(int i = 0; i < len; i++)
	{
		printf("%3d", data[i]);
	}
	printf("\n");
}
void InsertSort(int* data, int len)
{
	int i, j, temp;
	for(i = 1; i < len; i++)
	{
		if(data[i] < data[i-1])
		{
			temp = data[i];
			for(j = i - 1; j > 0 && data[j] > temp; j--)
			{
				data[j+1] = data[j];
			}
			data[j + 1] = temp;
		}
	}

}

void BinInsertSort(int* data, int len)
{
	int i, j, low, mid, high, temp;
	for(int i = 1; i < len; i++)
	{
		low = 0, high = i - 1;
		while(low <= high)
		{
			mid = (low + high) / 2;
			if(data[mid] > data[i])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}

		}
		// data[high] < temp;
		temp = data[i];
		for(j = i; j > high + 1; j--)
		{
			data[j] = data[j - 1];
		}
		data[high + 1] = temp;
	}
}

int main()
{
	printf("First!\n");
	int arr[10] = {1,9, 6, 8, 10, 5, 3, 2, 4, 7};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("Before Sort!\n");
	PrintArr(arr, len);
	//InsertSort(arr, len);
	BinInsertSort(arr, len);
	printf("After Sort!\n");
	PrintArr(arr, len);
	printf("\n");
	return  0;

}