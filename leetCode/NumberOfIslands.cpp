#include <vector>

using namespace std;

class Solution {
public:
    int dfs(vector<vector<char>>& grid, int x, int y){
        
        if(y < 0 || x < 0 || y >= grid.size() || x >= grid[0].size() || grid[y][x] == '0'){
            return 0;
        }
        
        //sink the island
        grid[y][x] ='0';
        
        dfs(grid, x    ,y+1);
        dfs(grid, x    ,y-1);
        dfs(grid, x -1 ,y);
        dfs(grid, x +1 ,y);

        return 1;
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        
        int islandCount=0;
        
        for(int y =0; y < grid.size(); y++){
            for(int x=0; x< grid[y].size(); x++){
                if(grid[y][x] == '1'){
                    islandCount+=dfs(grid, x,y);
                }
                
            }
        }
        
        return islandCount;
    }
};