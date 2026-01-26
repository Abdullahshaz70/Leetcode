class Solution {
public:
    vector<string> split_by_whitespace(const string& str) {
    stringstream ss(str);
    string word;
    vector<string> tokens;

    while (ss >> word) 
        tokens.push_back(word);
    
    return tokens;
}

int lengthOfLastWord(string s) {

    vector<string> tokens = split_by_whitespace(s);

    string r = tokens[tokens.size() - 1];

    return r.size();
}

};