class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

    vector<int> result;

    int size = nums.size();

    for (int i = 0; i < size; i++) {

        if (nums[i] == target) {
            result.push_back(i);
            int count = i + 1;
            for (int j = i+1; j < size; j++) {

                if (nums[j] == target)
                    count++;
                else
                    break;
            }
            
            result.push_back(count-1);

        }

        if (result.size() > 1)
            return result;
    }

    
    result.push_back(-1);
    result.push_back(-1);


    return result;
}

};