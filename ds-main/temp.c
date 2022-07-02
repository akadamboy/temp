#include <stdio.h>

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int l, int h, int mid) {
    int tmp[h], i = l, j = mid + 1, k = l;
    while (i <= mid && j <= h) {
        if (arr[i] > arr[j])
            tmp[k++] = arr[j++];
        else
            tmp[k++] = arr[i++];
    }

    while (j <= h)
        tmp[k++] = arr[j++];
    while (i <= mid)
        tmp[k++] = arr[i++];

    for (int i = l; i <= h; i++)
        arr[i] = tmp[i];
}

void mergeSort(int arr[], int l, int h) {
    if (l >= h) return;
    int mid = (l + h) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, h);
    merge(arr, l, h, mid);
}

int main() {
    int arr[] = {43, 13, 5, 33, 643, 3, 6, 24, 62, 4, 35, 26, 435, 635};
    // int arr[] = {1, 4, 6, 8, 12, 2, 5, 6, 7, 8, 11, 56};

    int n = sizeof(arr) / sizeof(arr[0]);

    print_arr(arr, n);
    mergeSort(arr, 0, n - 1);
    print_arr(arr, n);
}