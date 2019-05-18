#include <stdio.h>
#include <time.h>
#define MAX 100000

int temp[MAX];

void mergesort(int* arr, int lo, int hi) {
	
	int mid = (lo + hi) >> 1;
	int start = lo, end = mid + 1;

	if (lo >= hi) return;

	mergesort(arr, lo, mid);
	mergesort(arr, mid + 1, hi);

	for (int i = lo; start <= mid || end <= hi; ++i) {
		if ((end <= hi && start <= mid && arr[start] < arr[end]) || end > hi) {
			temp[i] = arr[start++];
		}
		else {
			temp[i] = arr[end++];
		}
	}

	for (int i = lo; i <= hi; ++i)
		arr[i] = temp[i];
}

int main() {
	srand(time(NULL));
	int arr[MAX];
	for (int i = 0; i < MAX; ++i)
		arr[i] = rand();
	mergesort(arr, 0, MAX - 1);
	return 0;
}