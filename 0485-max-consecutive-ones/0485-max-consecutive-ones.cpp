class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;
    vector<int> result;

    for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i]==0){
            result.push_back(count);
            count=0;
        }
        else
            count++;
    }

    result.push_back(count);

    return *max_element(result.begin() , result.end());

}
};