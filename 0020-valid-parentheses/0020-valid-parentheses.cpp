class Solution {
public:
bool isValid(string s) {

	vector<char> r;

	int size = s.length();
	bool flag = false;
	for (int i = 0; i < size; i++) {

		if (s[i] == '[' or s[i] == '(' or s[i] == '{')
			r.push_back(s[i]);

		else if (i == 0 and (s[i] == ')' or s[i] == '}' or s[i] == ']'))
			return false;

		else
		{

			if (r.size() != 0) {

				if ((s[i] == ')' and r[r.size() - 1] == '(')
					or
					(s[i] == ']' and r[r.size() - 1] == '[')
					or
					(s[i] == '}' and r[r.size() - 1] == '{'))
				{
					r.pop_back();
					flag = true;
				}
				else
					return false;
			}
			else
				return false;


		}

	}

	if (r.size() == 0 and flag )
		return true;

	return false;
}




};