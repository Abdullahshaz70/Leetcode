class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

	int sum = 0;
	
	priority_queue<int> number_of_boxes(capacity.begin(), capacity.end());

	for (auto a : apple)
		sum += a;

	int i = 0;

	while (sum>0) {

		sum -= number_of_boxes.top();
		number_of_boxes.pop();

		i++;
	}

	return i;



}

};