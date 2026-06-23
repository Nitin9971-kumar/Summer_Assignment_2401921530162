#include<iostream>
#include<vector>
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

void inorderTraversal(node*root,vector<int>&ans){
    if(root == NULL)
        return;
    

    inorderTraversal(root->left,ans);
    ans.push_back(root->data);
    inorderTraversal(root->right,ans);
}
int main(){
    node*root = NULL;
    root = createBinaryTree(root);

    vector<int>ans;
    inorderTraversal(root,ans);

    cout << "Inorder Traversal : " << endl;
    for(auto value : ans)
        cout << value << " ";
    cout << endl;

    return 0;
}
