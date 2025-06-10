#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
    data=val;
    next = prev = NULL;
    }
};
class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;
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
    void insert(int val, int position) {
    int cnt = 1;
    Node* newNode = new Node(val);

    if (position == 1) { 
        newNode->next = head;
        newNode->prev = NULL;
        if (head) head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (cnt < position - 1 && temp->next != NULL) { 
        temp = temp->next;
        cnt++;
    }

    if (cnt != position - 1) {
        cout << "Position does not exist\n";
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
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
    dll.insert(50,1);
    temp = dll.head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;

}