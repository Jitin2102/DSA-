#include <stdio.h>

void RinsertionSort(int arr[], int n) {
    if (n <= 1) { 
        return;
    }
    RinsertionSort(arr, n - 1);
    int key = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    RinsertionSort(arr, n);
    printf("Sorted array: \n");
    for(int i = 0;i < n;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
