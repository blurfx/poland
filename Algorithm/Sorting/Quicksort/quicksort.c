#include <stdio.h>
#include <time.h>
#define MAX 100000

int partition(int* arr, int lo, int hi) {
	int pivot = arr[hi];
	int i = lo;
	for (int j = lo; j <= hi - 1; ++j) {
		if (arr[j] < pivot) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			++i;
		}
	}
	int temp = arr[i];
	arr[i] = arr[hi];
	arr[hi] = temp;
	return i;
}


void quicksort(int* arr, int lo, int hi) {
	if (lo < hi) {
		int p = partition(arr, lo, hi);
		quicksort(arr, lo, p - 1);
		quicksort(arr, p + 1, hi);
	}
}


int main() {
	srand(time(NULL));
	int arr[MAX];
	for (int i = 0; i < MAX; ++i)
		arr[i] = rand();
	quicksort(arr, 0, MAX - 1);
	return 0;
}