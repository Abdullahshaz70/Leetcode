#include<iostream>
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


int getHeight(TreeNode* root , int &diameter){
    if(!root) return 0;

    int left = getHeight(root->left , diameter);
    int right= getHeight(root->right , diameter);

    diameter = max(diameter , left + right);
    return 1 + max(left , right);

}


int diameterOfBinaryTree(TreeNode* root) {
    
    int diameter = 0;

    getHeight(root , diameter);

    return diameter;

}

int main(){

    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    // TreeNode* n3 = new TreeNode(3);
    // TreeNode* n4 = new TreeNode(4);
    // TreeNode* n5 = new TreeNode(5);

    n1->left = n2;
    // n1->right = n3;
    // n2->left = n4;
    // n2->right = n5;

    TreeNode* root = n1;

    cout<<diameterOfBinaryTree(root)<<endl;

    return 0;
}