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
    return 0;
}