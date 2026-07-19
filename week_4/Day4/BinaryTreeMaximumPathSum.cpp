#include <iostream>
#include <climits>
#include <algorithm>
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

int solve(node* root, int &maxSum) {

    // Base Case
    if (root == NULL)
        return 0;

    // Maximum gain from left subtree
    int left = max(0, solve(root->left, maxSum));

    // Maximum gain from right subtree
    int right = max(0, solve(root->right, maxSum));

    // Path passing through current node
    int currentPath = left + right + root->data;

    // Update answer
    maxSum = max(maxSum, currentPath);

    // Return maximum gain to parent
    return root->data + max(left, right);
}

int maximumPathSum(node* root) {

    int maxSum = INT_MIN;

    solve(root, maxSum);

    return maxSum;
}

int main() {


    node* root = new node(-10);

    root->left = new node(9);

    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(7);

    cout << "Maximum Path Sum = " << maximumPathSum(root);

    return 0;
}
