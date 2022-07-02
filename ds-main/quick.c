#include <stdio.h>

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int l, int h) {
    int i = l, j = h, pivot = arr[l];
    do {
        do {
            i++;
        } while (arr[i] <= pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
            swap(&arr[i], &arr[j]);
    } while (i < j);
    swap(&arr[j], &arr[l]);
    return j;
}

void quickHelper(int arr[], int l, int h) {
    if (l >= h) return;
    int j = partition(arr, l, h);
    quickHelper(arr, l, j);
    quickHelper(arr, j + 1, h);
}

void quick(int arr[], int n) {
    quickHelper(arr, 0, n - 1);
}

int main() {
    int arr[] = {43, 13, 5, 33, 643, 3, 6, 24, 62, 4, 35, 26, 435, 635, __INT_MAX__};
    int n = sizeof(arr) / sizeof(arr[0]);

    print_arr(arr, n);
    quick(arr, n);
    print_arr(arr, n);
}