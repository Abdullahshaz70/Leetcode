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



bool hasPathSum(TreeNode* root, int targetSum) {
    
    if(!root) return false;

    if(!root->left && !root->right)
        return targetSum == root->val;

    int sum = targetSum - root->val;

    return hasPathSum(root->left , sum) || hasPathSum(root->right , sum);

}

int main(){

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);

    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    
    if(hasPathSum(root,targetSum)) cout<<"YEs"<<endl;
    else cout<<"No";
    
    return 0;
}