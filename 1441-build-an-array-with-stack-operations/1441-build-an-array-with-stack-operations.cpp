class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

	vector<string> result;

	int count = 1;

	while (count <= target[target.size() - 1]) {

		auto it = find(target.begin(), target.end(), count);

		if (it == target.end()) {
			result.push_back("Push");
			result.push_back("Pop");
		}
		else
			result.push_back("Push");

		count++;

	}



	return result;

}

};