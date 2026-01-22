class Solution {
public:


vector<int> findDisappearedNumbers(vector<int>& nums) {

    int size = nums.size();

    vector<int> result;

	vector<bool> present(size + 1, false);

    for (int i = 0; i < size; i++)
		present[nums[i]] = true;

    for (int i = 1; i <= size; i++)
        if (present[i] == false)
            result.push_back(i);


    return result;

}




};