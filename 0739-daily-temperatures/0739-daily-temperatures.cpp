class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

	int size = temperatures.size();
	vector<int> result(size, 0);

	stack<int> index;

;
	
	for (int i = 0; i < size; i++) {


		while (index.size() > 0 and temperatures[i] > temperatures[index.top()]) {
			result[index.top()] = i  - index.top();
			index.pop();
		}
			index.push(i);
	}



	return result;
}

};
