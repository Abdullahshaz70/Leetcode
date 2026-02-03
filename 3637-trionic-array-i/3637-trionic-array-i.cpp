class Solution {
public:
   bool isTrionic(vector<int>& nums) {

	int p = -1;
	int q = -1;

	int i = 0;
	int size = nums.size();

	if (size < 4)
		return false;

	bool ch = false;

	while (i + 1 < size and nums[i] < nums[i + 1]) 
		i++;

	p = i;
	int j = i;

	while (j + 1 < size and nums[j] > nums[j + 1])
		j++;

	q = j;

	if (q == size-1 or p == size-1)
		return false;

	for (int i = 0; i + 1 <= p; i++) {
		
		if (nums[i] >= nums[i + 1])
			return false;

		ch = true;
	}

	if (!ch)
		return false;

	for (int i = p; i + 1 <= q; i++) {

		if (nums[i] <= nums[i + 1])
			return false;
		ch = false;
	}

	if (ch)
		return false;

	for (int i = q; i + 1 < size; i++) {

		if (nums[i] >= nums[i + 1])
			return false;
		ch = true;
	}

	if (!ch)
		return false;
	

	return true;
}


};