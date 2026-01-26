class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

	

	int size = arr.size();

	vector<vector<int>> pArray(size - 1, vector<int>(2, 0));

	sort(arr.begin() , arr.end());

	for (int i = 0; i+1 < size; i++) {
		pArray[i][0] = (arr[i]);
		pArray[i][1] = (arr[i+1]);
	}

	vector<int> diff(size - 1 , 0);

	for (int i = 0; i < size - 1; i++) 
		diff[i] = pArray[i][1] - pArray[i][0];


	for (auto d : diff)
		cout << d << " ";
	cout << endl;


	int minimum = *min_element(diff.begin() , diff.end());

	int index = 0;

	vector<vector<int>> result;

	for (int i = 0; i < size - 1; i++) {

		if (diff[i] == minimum)
			result.push_back(pArray[i]);


	}



	return result;

}

};