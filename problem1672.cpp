#include<iostream>
#include<vector>
using namespace std;
int maximumWealth(vector<vector<int>>& accounts) {

    vector<int> result;

    int rows = accounts.size();
    int cols = accounts[0].size();

    for(int i = 0 ; i < rows ; i++){
        int sum = 0;
        for(int j = 0 ; j < cols ; j++){
            sum+=accounts[i][j];
        }

        result.push_back(sum);
        
    }
    
    return *max_element(result.begin() , result.end());
}

int main(){

    return 0;
}