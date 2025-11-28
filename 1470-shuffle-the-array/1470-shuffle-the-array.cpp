class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
    
    int size = nums.size();

    vector<int> a (nums.begin() , nums.end()-size/2);
    vector<int> b (nums.begin()+size/2 , nums.end());

    vector<int> result;

    int i = 0;

    while(result.size()!=size){
        result.push_back(a[i]);
        result.push_back(b[i]);
        i++;
    }

    return result;

}
};