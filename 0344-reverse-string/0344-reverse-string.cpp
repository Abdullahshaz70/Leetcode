class Solution {
public:
    void reverseString(vector<char>& s) {

    int i = 0;
    int size = s.size() - 1;

    while (i < size) {
        char c = s[i];
        s[i] = s[size];
        s[size] = c;

        size--;
        i++;
    }

}

};