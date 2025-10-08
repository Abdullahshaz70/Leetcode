#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode* root , TreeNode*& curr){

    if(!root) return;

    inorder(root->left , curr);

    root->left = nullptr;
    curr->right = root;

    curr = root;

    inorder(root->right , curr);

}

TreeNode* increasingBST(TreeNode* root) {
        
    if(!root) return nullptr;

    TreeNode dummy(-1);

    TreeNode* curr = &dummy;

    inorder(root , curr);

    return dummy.right;

}

int main(){


    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->left->left->left = new TreeNode(1);

    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);

    root = increasingBST(root);


    while(root){

        cout<<root->val<<" ";

        root = root->right;
    }

    return 0;
}