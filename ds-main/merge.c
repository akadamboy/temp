#include <stdio.h>

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l, tmp[h];
    while (i <= mid && j <= h)
        if (arr[i] < arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    while (i <= mid)
        tmp[k++] = arr[i++];
    while (j <= h)
        tmp[k++] = arr[j++];
    for (int i = l; i <= h; i++)
        arr[i] = tmp[i];
}

void mergeSortHelper(int arr[], int l, int h) {
    if (l >= h) return;
    int mid = (l + h) / 2;
    mergeSortHelper(arr, l, mid);
    mergeSortHelper(arr, mid + 1, h);
    merge(arr, l, mid, h);
}

void mergeSort(int arr[], int n) {
    mergeSortHelper(arr, 0, n - 1);
}

int main() {
    int arr[] = {43, 13, 5, 33, 643, 3, 6, 24, 62, 4, 35, 26, 435, 635};
    int n = sizeof(arr) / sizeof(arr[0]);

    print_arr(arr, n);
    mergeSort(arr, n);
    print_arr(arr, n);
}