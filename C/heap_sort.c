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

// Heapify Function
void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {

        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// Heap Sort
void heapSort(int arr[], int n) {

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {

        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {

    srand(time(NULL));

    int startSize = 8000;
    int step = 4000;
    int iterations = 8;

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
        heapSort(arr, size);
        end = clock();

        timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Size: %d | Random     : %.3f ms\n", size, timeTaken);

        // Ascending Array
        generateAscending(arr, size);

        start = clock();
        heapSort(arr, size);
        end = clock();

        timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Size: %d | Ascending  : %.3f ms\n", size, timeTaken);

        // Descending Array
        generateDescending(arr, size);

        start = clock();
        heapSort(arr, size);
        end = clock();

        timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Size: %d | Descending : %.3f ms\n\n", size, timeTaken);

        free(arr);
    }

    return 0;
}
