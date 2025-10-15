#include<iostream>
#include<vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    
    vector<int> result;

    int size = nums.size();
    int sum = 0;
    for(int i = 0 ; i < size ; i++){
        sum += nums[i];
        result.push_back(sum);
       
    }

    return result;

}

int main(){

    vector<int> nums = {1,2,3,4};

    vector<int> result = runningSum(nums);

    for(auto i: result)
        cout<<i<<" ";

    return 0;
}

