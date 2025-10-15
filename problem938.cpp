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

TreeNode* find(TreeNode* root , int key){

    if (!root) return nullptr;

    if(root->val == key)
        return root;


    if(key< root->val)
        return find(root->left , key);
    else if(key>root->val)
        return find(root->right , key);
    
    return nullptr;
}

int rangeSumBST(TreeNode* root, int low, int high) {
    if(!root) return 0;
    int sum = 0;

    for(int i = low ; i <= high ; i++){
        // cout<<i<<" ";
        TreeNode* n = find(root , i);   
        if(n)
        sum += n->val;
    }

    return sum;


}

int main(){

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    int low = 7;
    int high = 15;

    cout<<"The sum of range will be : "<<rangeSumBST(root , low , high);

    return 0;
}