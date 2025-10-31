#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {

    int size = nums.size();

    if(k> size)
        return -1;

    priority_queue<int> pq(nums.begin() , nums.end());

    int i = 0;
    int s = -1;

    while(i<k){

        s = pq.top();
        pq.pop();

        i++;
    }

    return s;
    
}

int main(){

    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;

    cout<<"The Kth "<<k<<" larget element is: "<<findKthLargest(nums , k);

    return 0 ;
}