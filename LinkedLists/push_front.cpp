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
    void push_front(int val){
        Node* newNode =new Node(val);
        if(head==NULL){
            head =tail =newNode;
        }
        else{
            
            newNode->next =head;
            head->prev =newNode;
            head =newNode;
        }
    }

};
int main(){
    DoublyLinkedList dll;
    dll.head = nullptr;
    dll.tail = nullptr;
    dll.push_front(10);
    dll.push_front(20);
    dll.push_front(30);
    
    Node* temp = dll.head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}