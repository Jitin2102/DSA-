#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) {
        key = k;
        left = right = nullptr;
    }
};
Node* rotateRight(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}
Node* splay(Node* root, int key) {
    if (!root || root->key == key) return root;
    // LL
    if (key < root->left->key) {
        root->left->left = splay(root->left->left, key);
        root = rotateRight(root);
    }
    // LR
    else if (key > root->left->key) {
        root->left->right = splay(root->left->right, key);
        if (root->left->right) root->left = rotateLeft(root->left);

        return (root->left == nullptr) ? root : rotateRight(root);
    } else {
        if (!root->right) return root;
        // RL
        if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left) root->right = rotateRight(root->right);
        }
        // RR
        else if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = rotateLeft(root);
        }
        return (root->right == nullptr) ? root : rotateLeft(root);
    }
}

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    root = splay(root, key);
    if (root->key == key) return root;
    Node* newNode = new Node(key);

    if (key < root->key) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr;
    }
    return newNode;
}

Node* Search(Node* root, int key) { return splay(root, key); }
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

    cout << "Preorder Traversal of Splay Tree: ";
    inOrder(root);
    cout << endl;
    return 0;
}
