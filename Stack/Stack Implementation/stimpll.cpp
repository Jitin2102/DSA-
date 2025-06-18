#include<iostream>
#include<list>
using namespace std;
class Stack{
    list<int>ll;
    public:
    Stack(){}
    void push(int val){
        ll.push_front(val);
    }
    void pop(){
        if(!ll.empty()) {
            ll.pop_front();
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    bool isEmpty(){
        return ll.empty();
    }

    int  top(){
        return ll.front();
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
