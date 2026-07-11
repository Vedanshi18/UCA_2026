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

// Insertion Sort
void insertionSort(int arr[], int n) {

    for (int i = 1; i < n; i++) {

        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {

    srand(time(NULL));

    int startSize = 8000;
    int step = 4000;
    int iterations = 8;

    printf("========== Insertion Sort ==========\n\n");

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
        insertionSort(arr, size);
        end = clock();

        timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Size: %d | Random     : %.3f ms\n", size, timeTaken);

        // Ascending Array
        generateAscending(arr, size);

        start = clock();
        insertionSort(arr, size);
        end = clock();

        timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Size: %d | Ascending  : %.3f ms\n", size, timeTaken);

        // Descending Array
        generateDescending(arr, size);

        start = clock();
        insertionSort(arr, size);
        end = clock();

        timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Size: %d | Descending : %.3f ms\n\n", size, timeTaken);

        free(arr);
    }

    return 0;
}
