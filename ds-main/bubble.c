#include <stdio.h>
#include <stdbool.h>

void print_arr(int arr[], int n){
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble(int arr[], int n){
    n--;
    for(int i=0; i<n; i++)
        for(int j=0; j<n-i; j++)
            if(arr[j]> arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int main(){
    int arr[] = {43,13,5,33,643,3,6,24,62,4,35,26,435,635};
    int n  = sizeof arr/ sizeof arr[0];
    print_arr(arr, n);
    bubble(arr, n);
    print_arr(arr, n);
}