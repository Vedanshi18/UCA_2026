//Count inversions in an array
#include <stdio.h>
#include <stdlib.h>

int merge (int arr[], int low, int mid, int high) {
    int n = high - low + 1;
    int temp[n];
    int left = low, right = mid + 1, k = 0, count = 0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        } else {
            count += (mid - left + 1);
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
    return count;
}
int mergeSort (int arr[], int low, int high) {
    if (low >= high) return 0;
    int mid = low + (high - low) / 2;
    int count = 0;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}
int main() {
    int arr[] = {1, 2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", mergeSort(arr, 0, n - 1));
    return 0;
}