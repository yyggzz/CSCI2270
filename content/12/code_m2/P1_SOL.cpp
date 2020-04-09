#include <iostream>

using namespace std;

struct BSTNode 
{
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int sumRange(BSTNode* root, int min, int max) 
{
    int x = 0;
    if (root) {
        if (root->data >= min && root->data <= max) 
            x = x + root->data;

        if (min < root->data) 
            x = x + sumRange(root->left, min, max);
        
        if (max > root->data)
            x = x + sumRange(root->right, min, max);
    }

    return x;
}

int main()
{
    // Creating the BST (minimal example)
    BSTNode* root     = new BSTNode(9);
    root->left        = new BSTNode(7);
    root->right       = new BSTNode(16);
    root->left->left  = new BSTNode(4);
    root->left->right = new BSTNode(8);
    root->right->left = new BSTNode(11);

    // Call the sumRange function
    cout << "[8, 12]: " << sumRange(root, 8, 12) << endl;
    cout << "[8, 10]: " << sumRange(root, 8, 10) << endl;

    return 0;
}