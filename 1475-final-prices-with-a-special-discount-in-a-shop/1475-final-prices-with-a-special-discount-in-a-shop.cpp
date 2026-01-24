class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

	int size = prices.size();

	vector<int> result = prices;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			if (j > i and prices[j] <= prices[i]) {
				result[i] = prices[i] - prices[j];
				break;
			}
		}
	}

	return result;

}

};