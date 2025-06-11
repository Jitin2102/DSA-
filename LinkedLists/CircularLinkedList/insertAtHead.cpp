#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class CircularLinkedList {
public:
    Node* head;
    Node* tail;
    CircularLinkedList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail= newNode;
            newNode->next = head; 
        } else {
            
            newNode->next = head;
            head = newNode;
            tail->next = newNode; 
            
        }
    }

    
};
int main() {
    CircularLinkedList cll;
    cll.push_front(10);
    cll.push_front(20);
    cll.push_front(30);

    Node* current = cll.head;
    if (current != NULL) {
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != cll.head);
    }
    cout << endl;

    return 0;
}   
