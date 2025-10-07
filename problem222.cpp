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

int countNodes(TreeNode* root) {

    int count =0;

    if(!root) return count;

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()){
        TreeNode* n = q.front(); q.pop();
        count++;

        if(n->left) q.push(n->left);
        if(n->right) q.push(n->right);
    }
    return count;
}

int main(){

     TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);

    // Build the BST manually (balanced structure)
    n3->left = n2;
    n3->right = n5;

    n2->left = n1;
    n5->left = n4;
    n5->right = n6;

    TreeNode* root = n3; // root = 3


    cout<<countNodes(root)<<endl;

    return 0;
}