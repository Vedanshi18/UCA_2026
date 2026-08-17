#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(void *a, void *b, size_t size) {
    void *temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

void heapify(void *arr, int n, int i, size_t size, int (*cmp)(const void *, const void *)) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    char *base = (char *)arr;

    if (left < n && cmp(base + left * size, base + largest * size) > 0) {
        largest = left;
    }
    if (right < n && cmp(base + right * size, base + largest * size) > 0) {
        largest = right;
    }

    if (largest != i) {
        swap(base + i * size, base + largest * size, size);
        heapify(arr, n, largest, size, cmp);
    }
}

void heapSort(void *arr, int n, size_t size, int (*cmp)(const void *, const void *)) {
    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, size, cmp);
    }

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        char *base = (char *)arr;
        // Move maximum element to the end
        swap(base, base + i * size, size);
        // Heapify remaining heap
        heapify(arr, i, 0, size, cmp);
    }
}

int compareInt(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x > y)
        return 1;
    if (x < y)
        return -1;

    return 0;
}

int compareFloat(const void *a, const void *b) {
    float x = *(const float *)a;
    float y = *(const float *)b;

    if (x > y)
        return 1;
    if (x < y)
        return -1;

    return 0;
}

void printIntArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void printFloatArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {50, 20, 40, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n, sizeof(int), compareInt);

    printf("Sorted integers: ");
    printIntArray(arr, n);

    float arr2[] = {3.4, 1.2, 5.6, 2.1, 4.8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    heapSort(arr2, n2, sizeof(float), compareFloat);

    printf("Sorted floats: ");
    printFloatArray(arr2, n2);

    return 0;
}