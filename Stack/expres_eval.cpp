#include<iostream>
using namespace std ;
//evaluating arithmetic expression using stack(Reverse Polish Notation) 
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};
class Stack{
    private:
      Node* top;
    public:
      Stack(){
        top=nullptr;
      }
      void push(int val) {
        Node* newNode = new Node(val);
        newNode -> next = top;
        top=newNode;
      }
      
      int pop(){
        if (top==nullptr) return -1;
        int val = top ->data;
        Node* temp = top;
        top = top ->next;
        delete temp;
        return val;  
      }
      bool isEmpty(){
        return top == nullptr;
      }
};

int main(){
    Stack st;
    st.push(5);
    st.push(3);
    st.push(4);
    int sum = st.pop() + st.pop();
    st.push(sum);
    st.push(8);
    int pdt= st.pop() * st.pop();
    st.push(pdt);
    int res = st.pop() - st.pop();

    cout<<sum <<endl;
    cout<<pdt <<endl;
    cout<<res<<endl;
    return 0;
}
