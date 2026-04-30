#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    Node * next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class SinglyLL {
    Node * head;
    public:
        SinglyLL() {
            head = NULL;
        }
    void insert_at_beginning(int data) {
        Node * newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
    }
    void insert_at_end(int data) {
        Node * newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node * curr = head;
        while (curr -> next) {
            curr = curr -> next;
        }
        curr -> next = newNode;
    }
    void insert(int val) {
        Node * newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node * curr = head;
        while (curr -> next) {
            curr = curr -> next;
        }
        curr -> next = newNode;
    }
    void removeNode(int val) {
        if (!head) return;

        if (head -> data == val) {
            Node * temp = head;
            head = head -> next;
            delete temp;
        }

        Node * curr = head;
        Node * prev = nullptr;

        while (curr && curr -> data != val) {
            prev = curr;
            curr = curr -> next;
        }

        if (curr) {
            prev -> next = curr -> next;
            delete curr;
        }
    }
    void display() {
        if (!head) {
            cout << "List is Empty";
            return;
        }
        Node * curr = head;
        while (curr) {
            cout << curr -> data << " ";
            curr = curr -> next;
        }
        cout << "\n";
    }
};

int main() {
    SinglyLL sl;
    sl.insert_at_beginning(10);
    sl.insert_at_beginning(20);
    sl.insert_at_end(30);
    sl.display();
    sl.insert_at_end(20);
    sl.insert_at_end(40);
    sl.display();
    sl.removeNode(20);
    sl.display();
    sl.insert(20);
    sl.display();
    return 0;
}