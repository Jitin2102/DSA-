#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int val){
        data=val;
        next =prev =nullptr;
    }
};
class DoublyLinkedList{
    public:
    Node *head;
    Node *tail;
    void push_back(int val){
        Node* newNode =new Node(val);
        if(head==NULL){
            head =tail =newNode;
        }
        else{
            
            tail->next =newNode;
            newNode ->prev =tail;
            tail =newNode;
        }
    }
    void pop_back(){
        Node* temp = tail;
        if(head == nullptr) {
            cout << "List is empty, nothing to pop." << endl;
            return;
        }
        else{
            tail = tail ->prev;
            if(tail != nullptr) {
                tail->next = nullptr; 
            } 
            temp->prev = nullptr;
            delete temp; 
        }
    }

};
int main(){
    DoublyLinkedList dll;
    dll.head = nullptr;
    dll.tail = nullptr;
    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);
    Node* temp = dll.head;
    while(temp != nullptr) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
    dll.pop_back(); // Assuming pop_back is implemented
    cout<<"After popping back"<<endl;
    temp = dll.head;
    while(temp != nullptr) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}