class Solution {
public:


int longestConsecutive(vector<int>& nums) {
    int max = 0;
    int count = 0;
    int n = nums.size();

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;


    sort(nums.begin(), nums.end());

    for (int i = 1; i < n; i++) {
        int diff = nums[i] - nums[i - 1];
        
        if (diff == 0)
            continue;

        if (diff == 1) {
            count += 1;
        }
        else 
            count = 0;
    
        if (max < count)
            max = count;
            
    }

    max += 1;
    

    return max;
                
}





};