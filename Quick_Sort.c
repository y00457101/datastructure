#include <stdio.h>
#include <stdlib.h>

int Partion(int *arr,int low,int high)
{
	int temp = arr[low];

	while (low < high) {
		while(low < high && arr[high] > temp) {
			high--;
		}
		
		if (low >= high) break;
		arr[low] = arr[high];

		while(low < high && arr[low] < temp) {
			low++;
		}
		
		if (low >= high) break;
		arr[high] = arr[low];
	}

	arr[low] = temp;
	return low;
}

void Quick(int *arr, int start, int end)
{
	int par = Partion(arr, start, end);

	if(par-1 > start) {
		Quick(arr, start, par-1);
	}
	
	if(par+1 < end) {
		Quick(arr, par+1, end);
	}
}

void QuickSort(int *arr, int lengh)
{
	Quick(arr, 0, lengh-1);
}
int main()
{
	int arr[] = {33,25,16,48,28,9,79};
	int len = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, len);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}