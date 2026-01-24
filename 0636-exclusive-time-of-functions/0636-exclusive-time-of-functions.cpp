class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {

	vector<int> result(n, 0);

	stack<int> callStack;

	int lastTimeStamp = 0;

	for (auto log : logs) {

		int pos1 = log.find(":");
		int pos2 = log.find(":", pos1 + 1);

		string part1 = log.substr(0, pos1);
		string part2 = log.substr(pos1+1, pos2 - pos1 - 1);
		string part3 = log.substr(pos2 + 1);


		if (part2 == "start"){
			
			if (callStack.size() > 0) {
				int prevID = callStack.top();
				result[prevID] += stoi(part3) - lastTimeStamp;
			}
			
			callStack.push(stoi(part1));

			lastTimeStamp = stoi(part3);

		}
		else {
			//int prevID = callStack.top();
			callStack.pop();

			result[stoi(part1)] += (stoi(part3) + 1) - lastTimeStamp;
			lastTimeStamp = stoi(part3)+1;
		}


	}


	return result;
}

};