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
    CircularLinkedList() {
        head = NULL;
    }

    void insertAthead(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head; 
        } else {
            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            newNode->next = head;
            tail->next = newNode; 
            head = newNode;
        }
    }

    void removeHead() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == head) {
            delete head;
            head = NULL;
        } else {
            Node* tail = head;
            while (tail->next != head) { 
                tail = tail->next;
            }
            Node* temp = head;
            tail->next = head->next; 
            head = head->next; 
            delete temp;
        }
    }
};
int main() {
    CircularLinkedList cll;
    cll.insertAthead(10);
    cll.insertAthead(20);
    cll.insertAthead(30);

    cout << "List before removing Head: ";
    Node* current = cll.head;
    if (current != NULL) {
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != cll.head);
    }
    cout << endl;

    cll.removeHead();

    cout << "List after removing head: ";
    current = cll.head;
    if (current != NULL) {
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != cll.head);
    }
    cout << endl;

    return 0;
}
