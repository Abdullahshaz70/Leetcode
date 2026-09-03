class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> sol;

    unordered_map< string, vector<string>> map;

    for (auto s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        map[key].push_back(s);
    }

    sol.resize(map.size());
    int idx = 0;
    for (auto p : map) {
        sol[idx] = p.second;
        idx++;
    }




    return sol;
}
};