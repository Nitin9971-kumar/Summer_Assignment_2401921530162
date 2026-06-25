#include<iostream>
#include<vector>
#include<limits.h>
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

node*insertIntoBst(node*root,int data){
    if(root == NULL){
        return new node(data);
    }

    if(root->data > data)
        root->left = insertIntoBst(root->left,data);

    else
        root->right = insertIntoBst(root->right,data);

    return root;
}

void createBst(node*&root){
    int data;
    cout << "Enter data : " << endl;
    cin >> data;

    while(data != -1){
        root = insertIntoBst(root,data);
        cin >> data;
    }
}

bool validateBinaryTree(node*root,int mini , int maxi){
    if(root == NULL)
        return true;

    if(root->data > mini && root->data < maxi){
        bool left = validateBinaryTree(root->left,mini,root->data);
        bool right = validateBinaryTree(root->right,root->data,maxi);

        return left && right;
    }

    else    
        return false;
}
int main(){
    node*root = NULL;
    createBst(root);

    cout << validateBinaryTree(root,INT_MIN,INT_MAX);
    return 0;
}
