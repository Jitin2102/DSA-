#include<iostream>
#include<vector>
using namespace std;

vector<int> minimax(int arr[], int n) {
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

    int minIndex = -1;
    int maxIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == minVal) {
            minIndex = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == maxVal) {
            maxIndex = i;
            break;
        }
    }

    return {minIndex, maxIndex};
}
int main() {
    int arr[] = {3, 5, 1, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> result = minimax(arr, n);
    cout << "Index of minimum element: " << result[0] << endl;
    cout << "Index of maximum element: " << result[1] << endl;
    return 0;
}
