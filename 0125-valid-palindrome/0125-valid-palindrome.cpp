class Solution {
public:
    bool isAllowed(const char& c) {

    if (c >= 'a' and c <= 'z')
        return true;

    if (c >= '0' and c <= '9')
        return true;

    if (c >= 'A' and c <= 'Z')
        return true;

    return false;
}

bool isPalindrome(string s) {

    int size = s.size();
    string temp_string;

    for (auto i : s) {
        if (isAllowed(i))
            temp_string.push_back(tolower(i));
    }

    

    string reverse_string;

    for (int i = temp_string.size()-1; i >= 0; i--)
        reverse_string.push_back(temp_string[i]);


    if (reverse_string == temp_string)
        return true;

    return false;
}


};