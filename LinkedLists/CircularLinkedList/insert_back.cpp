#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next =nullptr;
    }
};
class CircularLinkedList{
    public:
    Node*head;
    Node*tail;
    CircularLinkedList(){
        head =tail = nullptr;
      
    }
    void insertAttail(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
            tail->next = head;
        }else{
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
};
int main(){
    CircularLinkedList cll;
    cll.insertAttail(10);
    cll.insertAttail(20);
    cll.insertAttail(30);
    cll.insertAttail(40);
    Node* temp = cll.head;
    while(temp ->next != cll.head){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl; 
    return 0;
}