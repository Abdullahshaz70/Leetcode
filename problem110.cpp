#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getHeight(TreeNode* root){

    if(!root) return 0;

    return 1 + max(getHeight (root->left) , getHeight(root->right));
}

bool isBalanced(TreeNode* root) {

    if(!root) return true;

    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    return ((abs(lh-rh) <=1) && isBalanced(root->left) &&isBalanced(root->right));
}


int main(){

    TreeNode* root= nullptr;

    // TreeNode* root = new TreeNode(1);

    // root->left = new TreeNode(2);
    // root->right = new TreeNode(2);

    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(3);

    // root->left->left->left = new TreeNode(4);
    // root->left->left->right = new TreeNode(4);
    
    if(isBalanced(root)) cout<<"True"<<endl;
    else cout<<"No"<<endl;


    return 0;
}