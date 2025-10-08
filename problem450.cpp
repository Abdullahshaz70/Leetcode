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

void printLevel(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();  // number of nodes in this level

        while (size--) {
            TreeNode* node = q.front();
            q.pop();

            cout << node->val << " ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        cout << endl;  // new line after each level
    }
}

TreeNode* deleteNode(TreeNode* root, int key) {
    
    if(!root) return nullptr;

    if(key > root->val)
        root->right = deleteNode(root->right , key);

    else if (key < root->val)
        root->left = deleteNode(root->left , key);

    else{

        if(!root->left){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        if(!root->right){
            TreeNode* temp = root->left;
            delete root;
            return temp; 
        }

        TreeNode* succ = root->right;

        while(succ->left) succ = succ->left;

        root->val = succ->val;
        root->right = deleteNode(root->right , succ->val);
    }

    return root;
}

int main(){

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    root = deleteNode(root , 2);

    printLevel(root);

    return 0;
}



