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

void selection(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[min_idx] > arr[j])
        min_idx = j;
    }
    swap(&arr[min_idx], &arr[i]);
  }
}

int main() {
  int arr[] = {43, 13, 5, 33, 143, 3, 6, 24, 62, 4, 35, 26, 435, 35};
  int n = sizeof arr / sizeof arr[0];
  print_arr(arr, n);
  selection(arr, n);
  print_arr(arr, n);
  int *na;
}