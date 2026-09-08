class Solution {
public:

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result;
    int n = numbers.size();

    int left = 0;
    int right = n - 1;

    while (left < right) {

        int calc = numbers[left] + numbers[right];

        if (calc == target) {
            result.push_back(left + 1);
            result.push_back(right + 1);
            return result;
        }

        if (calc > target)
            right--;
        else
            left++;


    }


return result;
}
};