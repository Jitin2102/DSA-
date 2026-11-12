#include <bits/stdc++.h>
using namespace std;

// Backtracing // generating all binary strings of length n
void generateStrings(int n, string& s) {
    if (s.size() == n) {
        cout << s << '\n';
        return;
    }
    s.push_back('0');
    generateStrings(n, s);
    s.pop_back();

    s.push_back('1');
    generateStrings(n, s);
    s.pop_back();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        generateStrings(n, s);
    }
    return 0;
}
