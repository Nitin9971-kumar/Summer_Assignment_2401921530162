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

void levelOrderTraversal(node*root,vector<int>&ans){

    if(root == NULL)
        return;
    
    queue<node*>q;
    q.push(root);

    while(!q.empty()){
        node*temp = q.front();
        int value = temp->data;
        q.pop();

        ans.push_back(value);

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}
int main(){
    node*root = NULL;
    root = createBinaryTree(root);

    vector<int>ans;

    levelOrderTraversal(root,ans);
    cout << "Level order traversal is : " << endl;
    for(auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}
