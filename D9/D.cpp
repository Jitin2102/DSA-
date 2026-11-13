// Balanced Parentheses
// Approach 1 : Use a stack to keep track of opening brackets and check for
// matching closing brackets. -> O(n) time and O(n) space complexity.
// Approach 2 : Use a counter to keep track of the balance of parentheses,
// increment for opening and decrement for closing, ensuring it never goes
// negative and ends at zero. -> O(n) time and O(1) space complexity.
#include <bits/stdc++.h>
using namespace std;

bool balanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
                return false;
        }
    }

    return st.empty();
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        cout << (balanced(s) ? "YES" : "NO") << '\n';
    }

    return 0;
}
