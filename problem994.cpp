#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int orangesRotting(vector<vector<int>>& grid) {
    int minute = 0;    
    int rows = grid.size();
    int cols = grid[0].size();

    int fresh =0;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    queue<pair<int,int>> q;

        for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(grid[i][j] == 2){
                q.push({i, j});
                visited[i][j] = true;
            } else if(grid[i][j] == 1){
                fresh++;
            }
        }
    }


    if(fresh==0) return 0;
   


    vector<pair<int,int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    while(!q.empty()){

        int size = q.size();

        while(size--){

            pair<int,int> n = q.front() ; q.pop();
            
            for(int i = 0 ; i < 4 ; i++){
                int dx = n.first + directions[i].first;
                int dy = n.second + directions[i].second;
                
                if(dx >= 0 && dy >= 0 && dx < rows && dy < cols && grid[dx][dy] == 1 && !visited[dx][dy]){
                    visited[dx][dy] = true;
                    grid[dx][dy]=2;
                    q.push({dx,dy});
                    fresh--;
                }
            }
        }
        minute++;
    }


    return fresh==0?minute-1:-1;
}

int main(){

    vector<vector<int>> grid = {{1,2}};

    cout<<"The minute time is: "<<orangesRotting(grid)<<endl;


    return 0;
}