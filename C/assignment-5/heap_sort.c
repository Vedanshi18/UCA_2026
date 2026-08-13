#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            return 0;
    }
    return 1;
}

void createRandom(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand();
}

void createAscending(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = i;
}

void createDescending(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

int main() {
    srand(time(NULL));

    int sizes[] = {
        8000, 12000, 16000, 20000,
        24000, 28000, 32000, 36000
    };

    int numberOfSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("Size\t\tRandom\t\tAscending\tDescending\n");

    for (int s = 0; s < numberOfSizes; s++) {
        int n = sizes[s];
        int *arr = malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        double randomTime, ascendingTime, descendingTime;
        clock_t start, end;

        createRandom(arr, n);

        start = clock();
        heapSort(arr, n);
        end = clock();

        randomTime = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Random sorted correctly: %s\n",
               isSorted(arr, n) ? "YES" : "NO");

        createAscending(arr, n);

        start = clock();
        heapSort(arr, n);
        end = clock();

        ascendingTime = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Ascending sorted correctly: %s\n",
               isSorted(arr, n) ? "YES" : "NO");

        createDescending(arr, n);

        start = clock();
        heapSort(arr, n);
        end = clock();

        descendingTime = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Descending sorted correctly: %s\n",
               isSorted(arr, n) ? "YES" : "NO");
        printf("%d\t\t%.6f\t%.6f\t\t%.6f\n\n",
               n, randomTime, ascendingTime, descendingTime);

        free(arr);
    }
    return 0;
}