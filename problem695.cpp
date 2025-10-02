#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>>& grid , vector<vector<bool>>& visited , int r ,int c , int& index){

    
    if( r < 0 || c< 0 || grid.size()<=r || grid[0].size()<=c) return;
    if(visited[r][c] || grid[r][c]==0) return ;
    
    visited[r][c] = true;
    
    index++;

    dfs(grid, visited , r+1 , c , index) ;
    dfs(grid, visited , r-1 , c , index) ;
    dfs(grid, visited , r , c+1 , index) ;
    dfs(grid, visited , r , c-1 , index);    
    
        
    
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    
    int count=0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    vector<int> max;

    for(int i = 0 ; i < grid.size() ; i++){
        for(int j = 0 ; j < grid[i].size() ; j++){
            if(grid[i][j]==1 && !visited[i][j]){
                count=0;
                dfs(grid , visited , i , j , count);  
                max.push_back(count);
            }
        }
    }

   


    if(!max.empty())
        return *max_element(max.begin(), max.end());
    return 0;
}

int main(){

 vector<vector<int>> grid = {
    {0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}
};


int result = maxAreaOfIsland(grid);
    
cout<<result;


    return 0;
}