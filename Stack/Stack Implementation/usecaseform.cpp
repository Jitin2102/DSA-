#include<iostream>
#include<stack>
using namespace std;
int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    
    cout << "Top element: " << st.top() << endl; // Display top element
    
    while (!st.empty()) {
        cout << st.top() << " "; // Display and pop elements
        st.pop();
    }
    
    return 0;
}