#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate Random Array
void generateRandom(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

// Generate Ascending Array
void generateAscending(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = i;
}

// Generate Descending Array
void generateDescending(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

// Partition Function
int partition(int arr[], int low, int high) {

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] < pivot) {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int low, int high) {

    if (low < high) {

        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {

    srand(time(NULL));

    int startSize = 8000;
    int step = 4000;
    int iterations = 8;

    printf("========== Quick Sort ==========\n\n");

    for (int k = 0; k < iterations; k++) {

        int size = startSize + (k * step);

        int *arr = (int *)malloc(size * sizeof(int));

        if (arr == NULL) {
            printf("Memory Allocation Failed!\n");
            return 1;
        }

        clock_t start, end;
        double timeTaken;

        // Random Array
        generateRandom(arr, size);

        start = clock();
        quickSort(arr, 0, size - 1);
        end = clock();

        timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Size: %d | Random     : %.3f ms\n", size, timeTaken);

        // Ascending Array
        generateAscending(arr, size);

        start = clock();
        quickSort(arr, 0, size - 1);
        end = clock();

        timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Size: %d | Ascending  : %.3f ms\n", size, timeTaken);

        // Descending Array
        generateDescending(arr, size);

        start = clock();
        quickSort(arr, 0, size - 1);
        end = clock();

        timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Size: %d | Descending : %.3f ms\n\n", size, timeTaken);

        free(arr);
    }

    return 0;
}
