class Solution {
public:
    bool isNumber(const string& c) {

	try {

		int n = stoi(c);
	}
	catch (const invalid_argument c) {
		return false;
	}

	return true;
}


int evalRPN(vector<string>& tokens) {

	stack<int> numbers;
	stack<string> opr;
	
	int size = tokens.size();
	
	for (int i = 0; i < size; i++) {

		string c = tokens[i];

		if (isNumber(c)) 
			numbers.push(stoi(c));
		else {
			int b = numbers.top(); numbers.pop();
			int a = numbers.top(); numbers.pop();

			int sum = 0;

			if (c == "+")
				sum = a + b;
			else if (c == "-")
				sum = a - b;
			else if (c == "*")
				sum = a * b;
			else
				sum = a / b;

			numbers.push(sum);

		}

	}




	return numbers.top();
}

};