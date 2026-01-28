class Solution {
public:
    int triangularSum(vector<int>& nums) {

	int size = nums.size();
	//int sum = 0;

	int i = size;

	for (int j = 0; j < size; j++) {
		for (int i = 0; i + 1 < size - j; i++) 
			nums[i] = (nums[i] + nums[i + 1]) % 10;
	}
	


	return nums[0];
}

};