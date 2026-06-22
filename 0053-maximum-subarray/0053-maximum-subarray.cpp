class Solution {
public:
 int maxSubArray(vector<int>& nums) {

    int size = nums.size();

    int currentMAx = nums[0];
    int globalMAx = nums[0];

    for(int i = 1 ; i < size ; i++){
        currentMAx = max(nums[i] , currentMAx + nums[i]);
        globalMAx = max(currentMAx , globalMAx);
    }


    return globalMAx;


}


};