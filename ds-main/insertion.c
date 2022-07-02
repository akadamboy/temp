#include <stdio.h>

void print_arr(int arr[], int n){
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void insertion(int arr[], int n){
    for(int i=1; i<n; i++){
        int hold = arr[i], j=i-1;
        while(j>=0 && arr[j]>hold){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = hold;
    }
}

int main(){
    int arr[] = {43,13,5,33,143,3,6,24,62,4,35,26,435,35};
    int n  = sizeof arr/ sizeof arr[0];
    print_arr(arr, n);
    insertion(arr, n);
    print_arr(arr, n);
}