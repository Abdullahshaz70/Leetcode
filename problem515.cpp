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

int getMaxInQueue(queue<TreeNode*> q) {
    int maxVal = INT_MIN;
    while (!q.empty()) {
        maxVal = max(maxVal, q.front()->val);
        q.pop();
    }
    return maxVal;
}


vector<int> largestValues(TreeNode* root) {
    
    
    vector<int> result;
    
    if(!root) return result;
    
    queue<TreeNode*> q;

    q.push(root);
    q.push(nullptr);

    result.push_back(root->val);

    while(!q.empty()){

        TreeNode* n = q.front(); q.pop();

        if( q.size()>= 1 && n==nullptr){
            int max = getMaxInQueue(q);
            result.push_back(max);
            q.push(nullptr);
        }

        if(n && n->left) q.push(n->left);
        if(n && n->right) q.push(n->right);

        // if( q.size()> 1 && n==nullptr) 


    }

    return result;


}

int main(){

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);


    vector<int> result = largestValues(root);

    for(auto &i : result){
        cout<< i<< " ";
    }

    return 0;
}
