class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

	for (int i = 0; i < magazine.size(); i++) {

		if (ransomNote.size() > 0) {

			auto it = find(ransomNote.begin(), ransomNote.end(), magazine[i]);

			if (it != ransomNote.end())
				ransomNote.erase(it);
		}
		

	}

	if (ransomNote.size() == 0)
		return true;

	return false;



}

};