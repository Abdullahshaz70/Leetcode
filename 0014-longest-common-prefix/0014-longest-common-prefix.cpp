class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "No prefix!";
        }
        
        int length = 0;
        bool flag = false;
        int minLength = INT_MAX;

        // Find the string with the minimum length
        for (const string& str : strs) {
            minLength = min(minLength, (int)str.length());
        }

        // Compare characters in the same position across all strings
        for (int i = 0; i < minLength; i++) {
            char currentChar = strs[0][i];
            
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != currentChar) {
                    return (length == 0) ? "" : strs[0].substr(0, length);
                }
            }

            // If all strings match the character at position i
            length++;
        }
        
        return (length == 0) ? "" : strs[0].substr(0, length);
    }
};