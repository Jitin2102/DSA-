#include <bits/stdc++.h>
using namespace std;

// sort on the basis of multiple conditions
//  student marks and name are given ,sort students based on marks if marks of
//  two are equal ,then sort by name by lexicographical order

// Approach 1 : mannual sorting check one by one and swap the pairs -> O(n) time
// Approach 2 : using modified comparator
struct Student {
    string name;
    int score;
};

int main() {
    int n;
    cin >> n;
    vector<Student> a(n);
    for (auto& s : a) cin >> s.name >> s.score;
    sort(a.begin(), a.end(), [](const Student& x, const Student& y) {
        if (x.score != y.score) return x.score > y.score;
        return x.name < y.name;
    });
    for (auto& s : a) cout << s.name << " " << s.score << "\n";
    return 0;
}
