#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(vector<vector<int>>& image, int sr, int sc,int o , int color , vector<vector<bool>>& visited, vector<vector<int>>& result){

    int r = image.size();
    int c = image[0].size();

    if(sr<0 || sc<0 || sr>=r || sc>=c) return;

    if(visited[sr][sc] || image[sr][sc]!=o ) return;

    visited[sr][sc] = true;
    result[sr][sc] = color;

    dfs(image , sr-1 , sc ,o, color , visited, result);
    dfs(image , sr+1 , sc ,o, color , visited , result);
    dfs(image , sr , sc-1 ,o, color , visited , result);
    dfs(image , sr , sc+1 ,o, color , visited , result);
    
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    
    int r = image.size();
    int c = image[0].size();
    
    vector<vector<int>> result = image;
    vector<vector<bool>> visited(r , vector<bool>(c , 0));
    
   int originalColor = image[sr][sc];

    dfs(image , sr,sc,originalColor , color ,visited , result);

    return result;
    
}

void print2DVector(const vector<vector<int>>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    cout<<endl;
}

int main(){

    vector<vector<int>> image ={{1,1,1},{1,1,0},{1,0,1}};

    print2DVector(image);

    int sr = 1, sc = 1, color = 2;

    vector<vector<int>> result = floodFill(image , sr , sc , color);

    print2DVector(result);

    return 0;
}