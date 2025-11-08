#include<iostream>
#include<stack>
#include<cstring>
#include<string>
#include<vector>
#include<queue>


using namespace std;

vector<int> sortArray(vector<int>& nums) {
    vector<int> result;

    int size = nums.size();
    priority_queue< int , vector<int> , greater<int> > pq(nums.begin() , nums.end());

    for(int i = 0 ; i < size ; i++){
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}
int main(){

    vector<int> nums = {5,2,3,1};
    // vector<vector<int>> nums= {{0,1},{1,0}};
    // vector<vector<int>> nums= {{0,0,0},{1,1,0},{1,1,0}};

    nums = sortArray(nums);


    cout<<"The array will be: "<<endl;

    for(auto i:nums)
        cout<<i<<" ";
    




    return 0;

} 


