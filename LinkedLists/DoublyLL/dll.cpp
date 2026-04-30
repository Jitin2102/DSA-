#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    Node * next;
    Node*prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class DLL {
    Node * head;
    public:
    DLL(){
            head = NULL;
        }
    void insert(int data){
        Node* newNode = new Node(data);
        if( !head){
            head = newNode;
            return;
        }
       Node* curr= head;
       while(curr->next){
           curr = curr ->next;
       }
       curr->next = newNode;
       newNode ->prev = curr;
    }
    void removeNode(int val){
        if(!head) return;
        Node* curr = head;
        while(curr && curr->data != val){
            curr = curr->next;
        }
        if(!curr) return;
        if(curr == head) head = curr ->next;
        if(curr->prev) curr->prev->next = curr->next;
        if(curr->next) curr->next->prev = curr->prev;
    }
    void display() {
        if (!head) {
            cout << "List is Empty";
            return;
        }
        Node * curr = head;
        while (curr) {
            cout << curr -> data << "<->";
            curr = curr -> next;
        }
        cout << "NULL";
    }
};

int main() {
    DLL dl;
    dl.insert(10);
    dl.insert(20);
    dl.insert(30);
    dl.display();
    cout<<endl;
    dl.insert(20);
    dl.insert(40);
    dl.display();
    cout<<endl;
    dl.removeNode(20);
    dl.display();
    cout<<endl;
    dl.insert(20);
    dl.display();
    return 0;
}