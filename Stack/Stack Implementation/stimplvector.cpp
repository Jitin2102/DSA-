#include<iostream>
#include<vector>
using namespace std;
class Stack {
    private:
        vector<int> arr;
    public:
        Stack() {}

        void push(int val) {
            arr.push_back(val);
        }

        int top(){
            return arr[arr.size()-1];
        }
    
        int pop() {
            if (arr.empty()) return -1; // Indicating stack underflow
            int val = arr.back();
            arr.pop_back();
            return val;
        }

        bool isEmpty() {
            return arr.empty();
        }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.top() << endl;
    while(!st.isEmpty()) {
        cout << st.pop() << " ";
    }
    return 0;
}
