/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:


void helperFunc(TreeNode* root  ,int& count ,  int max) {
    
    
    if (!root)
        return;

    if (root->val >= max) {
        count++;
        max = root->val;
    }

    helperFunc(root->left, count, max);
    helperFunc(root->right, count, max);
}

int goodNodes(TreeNode* root) {
    if (!root)
        return 0;

    vector<int> curr_array;
   
    
    int count = 0;
    int max = root->val;
    
    helperFunc(root, count , max);

    return count;
}
    

};