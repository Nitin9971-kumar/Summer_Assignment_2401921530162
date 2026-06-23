#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


node*createBinaryTree(node*root){

    int data;
    cout << "Enter data : " << endl;
    cin >> data;

    if(data == -1)
        return NULL;

    root = new node(data);
    
    cout << "Enter data for left child : " << endl;
    root->left = createBinaryTree(root->left);

    cout << "Enter data for right child : " << endl;
    root->right = createBinaryTree(root->right);

    return root;
}

void invertBinaryTree(node*root){
    if(root == NULL)
        return;

    swap(root->left,root->right);

    invertBinaryTree(root->left);
    invertBinaryTree(root->right);
}
int main(){
    node*root = NULL;
    root = createBinaryTree(root);

    vector<int>ans;

    invertBinaryTree(root);
    return 0;
}
