class Solution {
public:
    
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> sol;

    vector<string> temp= strs;
    int n = strs.size();
    int index = 0;
    
    vector<bool> checker(n, false);

    for (int i = 0; i < n; i++)
        sort(temp[i].begin(), temp[i].end());

    for (int i = 0; i < n; i++) {

        if (checker[i])
            continue;
        
        sol.resize(sol.size() + 1);
        sol[index].push_back(strs[i]);
        checker[i] = true;
        
        for (int j = i + 1; j < n; j++) {
            if (checker[j] == false and (temp[i] == temp[j])) {


                //sol.resize(sol.size() + 1);

                sol[index].push_back(strs[j]);

                
                checker[j] = true;
            }

        }

        index++;
    }


    return sol;
}

};