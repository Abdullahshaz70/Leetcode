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

bool isSymmetric(TreeNode* root) {

    if(!root) return false;

    queue<TreeNode*> q;

    q.push(root->left);
    q.push(root->right);


    while(!q.empty()){

        TreeNode* n1 = q.front() ; q.pop();
        TreeNode* n2 = q.front() ; q.pop();

        if(!n1 && !n2) continue;

        if(!n1 || !n2 || n1->val!=n2->val) return false;

        q.push(n1->left);
        q.push(n2->right);


        q.push(n1->right);
        q.push(n2->left);

    }


    return true;

}

int main(){




    return 0;
}