#include<iostream>
#include<stack>
#include<cstring>
#include<string>
#include<vector>
#include<queue>


using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int pathLength = 0;

    int size = grid.size()-1;

    if(grid[0][0] == 1 || grid[size][size] == 1 )
        return -1;

    queue<pair<int , int>> q;

    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1},{1,-1},{1,1},{-1,-1},{-1,1}};

    q.push({0,0});
    grid[0][0] = 1;

    
    while(!q.empty()) {
    int sz = q.size(); 
    pathLength++;

    for(int i = 0; i < sz; i++) {
        auto [r, c] = q.front();
        q.pop();

        if (r == size && c == size)
            return pathLength;

        for (auto [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr >= 0 && nc >= 0 && nr <= size && nc <= size && grid[nr][nc] == 0) {
                q.push({nr, nc});
                grid[nr][nc] = 1;
            }
        }
    }
}

    return -1;

}

int main(){

    // vector<int> nums = {1,2,3,4};
    // vector<vector<int>> nums= {{0,1},{1,0}};
    vector<vector<int>> nums= {{0,0,0},{1,1,0},{1,1,0}};

    int result = shortestPathBinaryMatrix(nums);


    cout<<"The path steps will be as follows: "<<result<<endl;
    




    return 0;

} 


