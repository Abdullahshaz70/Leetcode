class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

	int maxSize = 0;

	int size = heights.size();

	stack<pair<int, int>> r;

	for (int i = 0; i < size; i++) {

		if (r.size() > 0) {

				int index = r.top().first;
				int value = r.top().second;
				bool flag = false;

			while (r.size() > 0 and value > heights[i]) {

				

				flag = true;
				

				if (r.size() > 0) {

					index = r.top().first;
					value = r.top().second;
				}
				maxSize = max((i - index) * value, maxSize);
				r.pop();


				if (r.size() > 0) 
					value = r.top().second;
				


			}
				
			if(flag)
				r.push({ index, heights[i] });
			else
				r.push({ i, heights[i] });

		}
		else
			r.push({ i , heights[i] });

	}


	while (r.size() > 0) {

		maxSize = max((size - r.top().first)*r.top().second, maxSize);
		r.pop();

	}
	

	


	

	return maxSize;

}

};