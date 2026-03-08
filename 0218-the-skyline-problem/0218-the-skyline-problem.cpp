class Solution {
public:
    void preprocess(const vector<vector<int>>& buildings, vector<vector<int>>& preprocess) {
    for (int i = 0; i < buildings.size(); i++) {
        preprocess.push_back({ buildings[i][0] , -buildings[i][2] });
        preprocess.push_back({ buildings[i][1] ,  buildings[i][2] });

    }

    sort(preprocess.begin(), preprocess.end());
}

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

    vector<vector<int>> pp;
    vector<vector<int>> result;

    preprocess(buildings, pp);
    multiset<int> st;
    st.insert(0);
    int prevHeight = 0;

    for (int i = 0; i < pp.size(); i++) {

        int first = pp[i][0];
        int second = pp[i][1];


        if (second < 0) {
            st.insert(-second);
        }
        else {
            st.erase(st.find(second));
        }

        int curr_heght = *st.rbegin();
        if (curr_heght != prevHeight) {
            result.push_back({first , curr_heght});
            prevHeight = curr_heght;
        }

    }


    return result;
}

};