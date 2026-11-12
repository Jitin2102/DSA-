#include <stdio.h>

void minimax(int arr[], int n, int *minIndex, int *maxIndex) {
    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    *minIndex = -1;
    *maxIndex = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == minVal) {
            *minIndex = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == maxVal) {
            *maxIndex = i;
            break;
        }
    }
}

int main() {
    int arr[] = {3, 5, 1, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int minIndex, maxIndex;

    minimax(arr, n, &minIndex, &maxIndex);

    printf("Index of minimum element: %d\n", minIndex);
    printf("Index of maximum element: %d\n", maxIndex);

    return 0;
}
