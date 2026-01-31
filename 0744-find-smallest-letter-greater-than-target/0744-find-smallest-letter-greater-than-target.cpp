class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
	
	if (target == 'z')
		return letters[0];
	
	vector<bool> check(26, false);


	for (int i = 0; i < letters.size(); i++)
			check[letters[i] - 'a'] = true;

	for (int i = 0; i < letters.size(); i++) {
		if (check[letters[i]-'a'] and letters[i]>target)
			return letters[i];
	}

return letters[0];
}
};