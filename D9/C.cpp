// Cycle in the linkedlist
//  appr 1: visit each node and mark as visited if we visit a  visited node then
//  there is a cycle appr 2: use two pointers slow and fast, move slow by one
//  step and fast by two steps, if they meet then there is a cycle
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
bool isCycle(Node* head) {
    if (head == NULL) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
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
        if (n > 0) {
            tail->next = head;
        }
        if (isCycle(head)) {
            cout << "Cycle detected" << endl;
        } else {
            cout << "No cycle" << endl;
        }
    }
}
