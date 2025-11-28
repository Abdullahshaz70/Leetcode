class Solution {
public:
 vector<int> findErrorNums(vector<int>& nums) {
    
    int size  = nums.size();

    vector<int> result(size+1);

    for(int i = 0 ; i < size ; i++)
        result[nums[i]] ++;

    int d = -1;
    int m = -1;


    for(int i = 1 ; i <= size ; i++){
        if(result[i]==2)
            d = i;
        if(result[i]==0)
            m = i;
    }

    return {d,m};

}

};