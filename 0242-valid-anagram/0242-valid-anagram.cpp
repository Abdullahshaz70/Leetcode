class Solution {
public:
bool isAnagram(string s, string t) {

    int size1 = s.size();
    int size2 = t.size();

    map <char, int> map1;
    map <char, int> map2;

    for (int i = 0; i < size1; i++)
        map1[s[i]]++;

    for (int i = 0; i < size2; i++)
        map2[t[i]]++;


    if (map1 == map2)
        return true;

    return false;
}

};