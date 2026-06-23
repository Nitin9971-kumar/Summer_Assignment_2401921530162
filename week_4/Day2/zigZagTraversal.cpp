#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> zigzagTraversal(node* root){
    vector<int> ans;

    if(root == NULL)
        return ans;

    queue<node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();

        vector<int> temp(size);

        for(int i = 0; i < size; i++){
            node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            temp[index] = frontNode->data;

            if(frontNode->left)
                q.push(frontNode->left);

            if(frontNode->right)
                q.push(frontNode->right);
        }

        for(int val : temp)
            ans.push_back(val);

        leftToRight = !leftToRight;
    }

    return ans;
}
