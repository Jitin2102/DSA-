#include<iostream>
#include<list>
using namespace std;
class Stack{
    list<int>ll;
    public:
    Stack(){}
    void push(int val){
        ll.push_back(val);
    }
    void pop(){
        if(!ll.empty()) {
            ll.pop_back();
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    bool isEmpty(){
        return ll.empty();
    }

    int  top(){
        return ll.back();
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);    
    st.push(30);
    cout << "Top element: " << st.top() << endl;
    while(!st.isEmpty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}