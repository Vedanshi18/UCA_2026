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

// Merge Function
void merge(int arr[], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

// Merge Sort
void mergeSort(int arr[], int left, int right) {

    if (left < right) {

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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
        mergeSort(arr, 0, size - 1);
        end = clock();

        timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Size: %d | Random     : %.3f ms\n", size, timeTaken);

        // Ascending Array
        generateAscending(arr, size);

        start = clock();
        mergeSort(arr, 0, size - 1);
        end = clock();

        timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Size: %d | Ascending  : %.3f ms\n", size, timeTaken);

        // Descending Array
        generateDescending(arr, size);

        start = clock();
        mergeSort(arr, 0, size - 1);
        end = clock();

        timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Size: %d | Descending : %.3f ms\n\n", size, timeTaken);

        free(arr);
    }

    return 0;
}
