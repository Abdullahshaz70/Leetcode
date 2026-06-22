class Solution {
public:
 


 vector<int> intersect(vector<int>& num1, vector<int>& num2) {
    unordered_map<int, int> freq;
    vector<int> ans;

    // count elements of first array
    for (int x : num1) {
        freq[x]++;
    }

    // check second array
    for (int x : num2) {
        if (freq[x] > 0) {
            ans.push_back(x);
            freq[x]--;  // to avoid duplicates
        }
    }

    return ans;
}

};