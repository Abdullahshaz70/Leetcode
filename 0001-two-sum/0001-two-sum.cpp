class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
            int size = nums.size();
        int s = 0;
        int temp = s + 1;
        bool haha = false;
        vector<int> result;

        while (s < size - 1) {
            if (nums[s] + nums[temp] == target && temp != s) {
                result.push_back(s);
                result.push_back(temp);
                haha = true;
                break;
            }
            temp++;
            if (temp == size) {
                s++;
                temp = s + 1;
            }
        }

        if (!haha) {
            cout << "NOT FOUND!" << endl;
        }
        
        return result;
    }
    
};