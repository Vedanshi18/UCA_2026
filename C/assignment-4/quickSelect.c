#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}
// QuickSelect
void quickSelect(int arr[], int low, int high, int k) {
    if(low >= high)
        return;
    int pivotIndex = partition(arr, low, high);
    if(pivotIndex == k)
        return;
    if(pivotIndex > k)
        quickSelect(arr, low, pivotIndex - 1, k);
    else
        quickSelect(arr, pivotIndex + 1, high, k);
}

int main() {
    srand(time(NULL));

    int arr[] = {12, 7, 3, 19, 5, 10, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    printf("Original Array:\n");

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\n");
    clock_t start = clock();
    quickSelect(arr, 0, n - 1, k - 1);
    clock_t end = clock();
    printf("Smallest %d elements:\n", k);

    for(int i = 0; i < k; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int sizes[] = { 100000, 200000, 400000, 800000, 1600000 };

    int totalSizes = sizeof(sizes) / sizeof(sizes[0]);
    printf("Dataset\t\tRuntime\n");

    for(int s = 0; s < totalSizes; s++) {
        int size = sizes[s];
        int *largeArray = (int *)malloc(size * sizeof(int));
        for(int i = 0; i < size; i++)
            largeArray[i] = rand();
        int largeK = size / 10;
        start = clock();
        quickSelect(largeArray, 0, size - 1, largeK - 1);
        end = clock();
        double runtime = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d\t\t%.6f\n", size, runtime);
        free(largeArray);
    }
    return 0;
}