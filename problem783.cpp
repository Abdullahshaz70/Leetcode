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

void inordertriversal(TreeNode* root , vector<int>& a){
    if(!root) return;

    inordertriversal(root->left , a);
    a.push_back(root->val);
    inordertriversal(root->right , a);
}

int minDiffInBST(TreeNode* root) {
    vector<int> a;
    if(!root) return 0;    
        inordertriversal(root , a);

    int min = INT_MAX;

    int size = a.size();

    for(int i = 0 ; i + 1 < size ; i++){

        int n = abs(a[i] - a[i+1]);

        if(n<min)
            min = n;

    }


    return min;
}


int main(){

    TreeNode* root = new TreeNode(543);
    root->left = new TreeNode(384);
    root->right = new TreeNode(652);

    root->left->right = new TreeNode(445);
    root->right->right = new TreeNode(699);

    cout<<minDiffInBST(root);


    return 0;
}