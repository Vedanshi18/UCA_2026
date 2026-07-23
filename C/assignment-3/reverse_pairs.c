// Count significant reverse pairs in an array
#include <stdio.h>
#include <stdlib.h>
int countPairs(int arr[], int low, int mid, int high) {
    // Start pointer in the right half
    int right = mid + 1;
    int count = 0;
    // Iterate over left elements
    for (int i = low; i<= mid; i++) {
        while (right <= high && (long long)arr[i] > 2LL * arr[right]) {
            right++;
        }
        count += right - (mid + 1);
    }
    return count;
}
void merge (int arr[], int low, int mid, int high) {
    int n = high - low + 1;
    int temp[n];
    int left = low, right = mid + 1, k = 0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
        }
    }
    //Copy remaining
    while(left <= mid) {
        temp[k++] = arr[left++];
    }
    while(right <= high) {
        temp[k++] = arr[right++];
    }
    //Back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
int mergeSort (int arr[], int low, int high) {
    if (low >= high) return 0;
    int mid = low + (high - low) / 2;
    int count = 0;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return count;
}
int main() {
    int arr[] = {1, 3, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", mergeSort(arr, 0, n - 1));
    return 0;
}