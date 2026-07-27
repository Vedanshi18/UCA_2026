#include <stdio.h>
int val[100000], idx[100000];
int tempVal[100000], tempIdx[100000];
int ans[100000];

void merge (int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int count = 0;

    while (i <= mid && j <= right) {
        if (val[j] < val[i]) {
            tempVal[k] = val[j];
            tempIdx[k] = idx[j];
            count++;
            j++;
        }
        else {
            ans[idx[i]] += count;
            tempVal[k] = val[i];
            tempIdx[k] = idx[i];
            i++;
        }
        k++;
    }

    while (i <= mid) {
        ans[idx[i]] += count;
        tempVal[k] = val[i];
        tempIdx[k] = idx[i];
        i++;
        k++;
    }

    while (j <= right) {
        tempVal[k] = val[j];
        tempIdx[k] = idx[j];
        j++;
        k++;
    }

    for (i = left; i <= right; i++) {
        val[i] = tempVal[i];
        idx[i] = tempIdx[i];
    }

}

void mergeSort(int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}
int main()
{
    int n = 4;

    val[0] = 5;
    val[1] = 2;
    val[2] = 6;
    val[3] = 1;

    for (int i = 0; i < n; i++)
    {
        idx[i] = i;
        ans[i] = 0;
    }
    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}