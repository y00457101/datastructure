#include <stdio.h>
#include <stdlib.h>

/* 冒泡排序 */
void bubble_sort(int arr[], int len)
{
    int i, j, temp;
    for (i = 0; i < len-1; i++) {
        for (j = 0; j < len-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/* 选择排序 */
void swap(int *a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void select_sort(int arr[], int len)
{
    int i, j, temp;
    for (i = 0; i < len-1; i++) {
        for (j = i+1; j < len; j++) {
            if ( arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

/* 插入排序 */
void insertion_sort(int arr[], int len){
    int i, j, temp;
    for (i = 1; i < len; i++){
        temp = arr[i];
        for (j = i; j>0 && arr[j-1] > temp; j--)
            arr[j] = arr[j-1];
        arr[j] = temp;
    }
}
/* 快速排序 */
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
  //    bubble_sort(arr, len);
  //    select_sort(arr, len);
  //    insertion_sort(arr, len);
	QuickSort(arr, len);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
