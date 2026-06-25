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

bool searchIntoBst(node*root,int target){
    if(root == NULL)
        return false;

    node*temp = root;
    while(temp != NULL){
        if(temp->data == target)
            return true;

        else if(temp->data > target)
            temp = temp -> left;

        else
            temp = temp->right;
    }

    return false;
}
int main(){
    node*root = NULL;
    createBst(root);

    int target;
    cout << "Enter target value : " << endl;
    cin >> target;

    cout << searchIntoBst(root,target) << endl;
    return 0;
}
