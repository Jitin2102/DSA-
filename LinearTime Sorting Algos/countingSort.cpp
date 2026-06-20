#include <iostream>
#include <vector>
#define INT_MIN
using namespace std;

void CountingSort(vector<int>& arr, vector<int>& res) {
    int n = arr.size();
    int maxV = arr[0];
    for (int i = 0; i < n; i++) maxV = max(maxV, arr[i]);  // maxV calculation
    vector<int> cnt(maxV + 1, 0);                          // counting frequency
    for (int j = 0; j < n; j++) cnt[arr[j]] = cnt[arr[j]] + 1;
    for (int i = 1; i <= maxV; i++)
        cnt[i] = cnt[i] + cnt[i - 1];  // cummutive frequency
    for (int j = n - 1; j >= 0; j--) {
        res[cnt[arr[j]] - 1] = arr[j];
        cnt[arr[j]] = cnt[arr[j]] - 1;
    }
}
int main() {
    vector<int> arr = {2, 5, 3, 0, 2, 3, 0, 3};
    int n = arr.size();
    vector<int> res(n, 0);
    CountingSort(arr, res);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}
