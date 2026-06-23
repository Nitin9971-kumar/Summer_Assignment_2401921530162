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

bool sameTree(node*root1,node*root2){

    if(root1 == NULL && root2 == NULL)
        return true;

    if(root1 == NULL && root2 != NULL)
        return false;

    if(root1 != NULL && root2 == NULL)
        return false;

    if(root1->data!= root2->data)
        return false;

    return sameTree(root1->left,root2->left) && sameTree(root1->right,root2->right);
}
int main(){
    node*root1 = NULL;
    node*root2 = NULL;

    root1 = createBinaryTree(root1);
    root2 = createBinaryTree(root2);

    bool ans = sameTree(root1,root2);

    if(ans)
        cout << "same tree : " << endl;
    else
        cout << "not same tree : " << endl;
    
    return 0;
}
