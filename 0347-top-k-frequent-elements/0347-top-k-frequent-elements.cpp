class Solution {
public:
using Entry = pair<int, int>;

struct Compare {

    bool operator()(const Entry& a, const Entry& b) const{
        if (a.second != b.second) 
            return a.second < b.second; 

        return a.first > b.first;
        
    }

};
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> sol;
    int n = nums.size();
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
        map[nums[i]]++;

    priority_queue < Entry , vector<Entry> , Compare> pq;

    for (auto e : map)
        pq.push(e);

    for (int i = 0; i < k; i++) {
        auto p = pq.top();
        pq.pop();

        sol.push_back(p.first);
    }
    


    return sol;

}


};