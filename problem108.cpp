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


void inorder(TreeNode* root){

    if(!root) return;

    inorder(root->left);

    cout<<root->val<<" ";

    inorder(root->right );

}

TreeNode* insert(vector<int>& nums , int start , int end){

    if(start>end) return nullptr;

    int mid = (start+end)/2;

    TreeNode* node = new TreeNode(nums[mid]);

    node->left = insert(nums , start , mid-1);
    node->right = insert(nums , mid+1 , end);

    return node;
}


TreeNode* sortedArrayToBST(vector<int>& nums) {
    
    return insert(nums , 0 , nums.size()-1);
    
}

int main(){


    vector<int>nums = {-10,-3,0,5,9};

    TreeNode* root = sortedArrayToBST(nums);

   inorder(root);

    return 0;
}