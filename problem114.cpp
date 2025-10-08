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


void t(TreeNode* root , TreeNode*& prev){

    if(!root)   return;

    if(prev) {
        prev->right = root;
        prev->left = nullptr;
    }

    prev = root;

    TreeNode* r = root->right;
    t(root->left , prev);
    t(r , prev);

    
}

void printList(TreeNode* root) {
    while (root) {
        cout << root->val;
        if (root->right) cout << " -> ";
        root = root->right;
    }
    cout << endl;
}

void flatten(TreeNode* root) {
    TreeNode* prev = nullptr;
    t(root , prev);

    printList(prev);
}

int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    flatten(root);

    

    return 0;
}






// This was submitted

//   void flatten(TreeNode* root) {
//         if(!root) return;

//         if(prev){
//             prev->right = root;
//             prev->left = nullptr;
//         }

//         prev = root;

//         TreeNode* r = root->right;
//         flatten(root->left);
//         flatten(r);
//     }