#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    
    vector<int> all;

    all.reserve(matrix.size() * matrix[0].size());

    for(auto row : matrix)
        all.insert(all.end() ,row.begin() , row.end());

    priority_queue<int, vector<int>, greater<int>> pq(all.begin(), all.end());

    int i = 0;
    
    int s = -1;
    while(i<k){

        s  = pq.top();
        pq.pop();
        i++;
    }

    return s;
    


}

int main(){

    // vector<vector<int>> matrix = {
    //     {1, 5, 9},
    //     {10, 11, 13},
    //     {12, 13, 15}
    // };
    vector<vector<int>> matrix = {{-5},};
    int k = 8;

    cout<<"The Kth "<<k<<" larget element is: "<<kthSmallest(matrix , k);

    return 0 ;
}