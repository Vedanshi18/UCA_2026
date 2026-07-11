#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITERATIONS 8
#define START_SIZE 8000
#define STEP 4000

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

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {

    srand(time(NULL));

    printf("========== Selection Sort ==========\n\n");

    for (int k = 0; k < ITERATIONS; k++) {

        int size = START_SIZE + (k * STEP);

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
        selectionSort(arr, size);
        end = clock();

        timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Size: %d | Random     : %.3f ms\n", size, timeTaken);

        // Ascending Array
        generateAscending(arr, size);

        start = clock();
        selectionSort(arr, size);
        end = clock();

        timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Size: %d | Ascending  : %.3f ms\n", size, timeTaken);

        // Descending Array
        generateDescending(arr, size);

        start = clock();
        selectionSort(arr, size);
        end = clock();

        timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Size: %d | Descending : %.3f ms\n\n", size, timeTaken);

        free(arr);
    }

    return 0;
}
