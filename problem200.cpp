#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<char>>& grid , vector<vector<bool>>& visited , int r ,int c){

    if( r < 0 || c< 0 || grid.size()<=r || grid[0].size()<=c) return;
    if(visited[r][c] || grid[r][c]=='0') return ;

    visited[r][c] = true;

     dfs(grid, visited , r+1 , c) ;
      dfs(grid, visited , r-1 , c) ;
       dfs(grid, visited , r , c+1) ;
        dfs(grid, visited , r , c-1);    
    
        

}

int numIslands(vector<vector<char>>& grid) {
    
    int count=0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));


    for(int i = 0 ; i < grid.size() ; i++){
        for(int j = 0 ; j < grid[i].size() ; j++){
            if(grid[i][j]=='1' && !visited[i][j]){
                dfs(grid , visited , i , j);
                    count++;
                
            }
        }
    }

    return count;
}

int main(){

    vector<vector<char>> grid = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
};

int result = numIslands(grid);
    
cout<<result;


    return 0;
}