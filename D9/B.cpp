// Find middle of the linked list
// Aprroach 1 : traverse the linked list and store the values in a vector, then
// print the middle value of the vector.
// Approach 2 : use two pointers slow and fast, move slow by one step and fast
// by two steps, when fast reaches the end, slow will be at the middle.
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node* head = NULL;
        Node* tail = NULL;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            Node* newNode = new Node(val);
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        Node* middle = findMiddle(head);
        if (middle != NULL) {
            cout << middle->data << endl;
        } else {
            cout << "List is empty" << endl;
        }
    }
}
