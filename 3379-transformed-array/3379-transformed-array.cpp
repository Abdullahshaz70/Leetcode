class Solution {
public:
vector<int> constructTransformedArray(vector<int>& nums) {

    int size = nums.size();

    vector<int> result(size);

    for (int i = 0; i < size; i++) {

        if (nums[i] > 0) {
           
            int number_we_Gonna_move_right = nums[i];

            int count = i;

            while (number_we_Gonna_move_right--) {
                count++;

                if (count == size)
                    count = 0;
            }

            result[i] = nums[count];

        }
        else if (nums[i] < 0) {
            
            int number_we_Gonna_move_left = abs(nums[i]);

            int count = i;

            while (number_we_Gonna_move_left--) {
                count--;

                if (count < 0)
                    count = size-1;
            }

            result[i] = nums[count];

        }
        else {
            result[i] = nums[i];
        }

    }

    return result;
}
};