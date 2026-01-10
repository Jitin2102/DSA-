#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k) {
        key = k;
        left = right = nullptr;
        height = 1;
    }
};

int height(Node* n) { return n ? n->height : 0; }

int getBalance(Node* n) { return n ? height(n->left) : 0; }

void updateHeight(Node* n) {
    if (n) n->height = 1 + max(height(n->left), height(n->right));
}
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* insert(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    updateHeight(node);
    int bal = getBalance(node);

    // Balannce access
    // Case - 1 (LL)
    if (bal > 1 && key < node->left->key) {
        return rotateRight(node);
    }
    // Case - 2 (LR)
    if (bal > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // Case - 3 (RR)
    if (bal < -1 && key > node->right->key) {
        return rotateLeft(node);
    }
    // Case - 4 (RL)
    if (bal < -1 && key < node->right->key) {
        node->right = rotateRight(node);
        return rotateLeft(node);
    }

    return node;
}
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder Traversal of Avl Tree:";
    inOrder(root);
    cout << endl;
    return 0;
}
