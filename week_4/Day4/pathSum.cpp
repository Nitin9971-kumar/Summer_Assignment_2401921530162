#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool hasPathSum(node* root, int targetSum) {

    // Base Case
    if (root == NULL)
        return false;

    // Leaf Node
    if (root->left == NULL && root->right == NULL) {
        return (targetSum == root->data);
    }

    // Remaining Sum
    int remainingSum = targetSum - root->data;

    // Check Left or Right Subtree
    return hasPathSum(root->left, remainingSum) ||
           hasPathSum(root->right, remainingSum);
}

int main() {


    node* root = new node(5);

    root->left = new node(4);
    root->right = new node(8);

    root->left->left = new node(11);
    root->left->left->left = new node(7);
    root->left->left->right = new node(2);

    root->right->left = new node(13);
    root->right->right = new node(4);
    root->right->right->right = new node(1);

    int targetSum = 22;

    if (hasPathSum(root, targetSum))
        cout << "Path Exists";
    else
        cout << "Path Does Not Exist";

    return 0;
}
