#include<iostream>
#include<stack>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    
    vector<int> result;
    vector<int> prefix;
    vector<int> sufix;

    int size = nums.size()-1;
    result.assign(size+1,-1);

    for(int i = 0 ; i <= size ; i++){

        if(i==0)
            prefix.push_back(1);
        else if (i>0 && i<=1)
            prefix.push_back(nums[i-1]);
        else
            prefix.push_back(nums[i-1]*prefix.back());
    }


    for(int i = size ; i>=0 ; i--){

        if(i==size)
            sufix.push_back(1);
        else if( i >= size-1)
            sufix.push_back(nums[i+1]);
        else
            sufix.push_back(nums[i+1]*sufix.back());

    }

    reverse(sufix.begin() , sufix.end());

    for(int i = 0 ; i <= size ; i++)
        result[i] = prefix[i]*sufix[i];
    

    return result;

}

int main(){

    // vector<int> nums = {1,2,3,4};
    vector<int> nums = {-1,1,0,-3,3};

    nums = productExceptSelf(nums);


    for (auto i : nums)
        cout<<i<<" ";
    
        cout<<endl;
    




    return 0;

} 


