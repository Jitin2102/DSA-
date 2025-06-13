#include<iostream>
using namespace std;

class Node{
    public:
     char data;
     Node* next;
     Node(char val){
        data = val;
        next = nullptr;
     }
};

class Stack{
    private:
     Node* top;
    public:
    Stack(){
        top = nullptr;

    }
    
    void push(char val){
        Node* newNode = new Node(val);
        newNode ->next = top;
        top = newNode;
    }

    char pop(){
        if (top == nullptr) return '\0';
        char val = top->data;
        Node* temp = top;
        top = top ->next;
        delete temp;
        return val;
    }

    bool isEmpty(){
        return top ==nullptr;
    }

    bool isBalanced( const char* expr){
        Stack st;
        for (int i = 0; expr[i]!= '\0' ; i++){
            if (expr[i] == '(') st.push(')');
            else if (expr[i] == ')') {
                if (st.isEmpty()) return false;
                st.pop();
            }
        }
        return st.isEmpty();

    }
};

int main(){
    Stack st;

    const char* expr="(5+3)*(2+(4/2))";
    bool isbalanced =st. isBalanced(expr);
    cout<<isbalanced<<endl; // 1 means parenthesis are balanced 
    cout<<expr;
    return 0;

}