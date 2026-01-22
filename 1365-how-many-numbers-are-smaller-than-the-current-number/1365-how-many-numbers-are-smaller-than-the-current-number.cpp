class Solution {
public:
   vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    
    int size = nums.size();

    vector<int> result(size , 0);
    int count =0;

    for(int i = 0 ; i < size ; i++){
        count=0;
        for(int j = 0 ; j < size ; j++){

            if(nums[i]!=nums[j] && nums[i]> nums[j])
                count++;

        }

        result[i] = count;
    }

    return result;
}

};