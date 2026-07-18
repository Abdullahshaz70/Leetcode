class Solution {
public:
  int firstUniqChar(string s) {
	unordered_map <char, int> hehe;
	
	for (char c : s)
		hehe[c]++;

	for (int i = 0; i < s.size(); i++)
	{
		if (hehe[s[i]] == 1)
			return i;
	}

	return -1;
}
};