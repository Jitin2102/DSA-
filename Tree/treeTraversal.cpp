#include<iostream>
using namespace std;
#include<vector>
 // Tree traversal
class Node{
    public:
    int data ;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
static int idx = -1;
Node* createBinaryTree(vector<int> &preOrder){
    idx++;
    if(preOrder[idx]==-1) return NULL;
    Node* root = new Node(preOrder[idx]);
    root->left = createBinaryTree(preOrder);
    root->right = createBinaryTree(preOrder);
    return root;
}

void preorderTraversal(Node* root){
    if (root== NULL) return;
    cout<<root->data<<" ";
    preorderTraversal(root-> left);
    preorderTraversal(root ->right);
}
void inorderTraversal(Node* root){
    if (root== NULL){
        return ;
    }
    preorderTraversal(root-> left);
    cout<<root->data<<" ";
    preorderTraversal(root ->right);
}
void postorderTraversal(Node* root){
    if (root== NULL){
        return ;
    }
    postorderTraversal(root-> left);
    postorderTraversal(root ->right);
    cout<<root->data<<" ";
}
int main(){
    vector<int>preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = createBinaryTree(preOrder);
    cout<<"PreOrder Traversal of Tree: ";
    preorderTraversal(root);
    cout<<"\nInorder Traversal of Tree: ";
    inorderTraversal(root);
    cout<<"\nPostorder Traversal of Tree: ";
    postorderTraversal(root);
    return 0;
}