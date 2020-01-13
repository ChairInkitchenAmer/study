#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, int i, int j, int count,string word){
        if(count == word.length()){
            return true;
        }
        
        //Check the bounds and character
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || 
           board[i][j] != word[count]){
            return false;
        }
        
        //save the value 
        char temp = board[i][j];
        
        board[i][j]=' ';
        //perform dfs again
        bool found= dfs(board, i+1, j, count+1, word) ||  dfs(board, i-1, j, count+1, word) ||
             dfs(board, i, j+1, count+1, word) || dfs(board, i, j-1, count+1, word);
        
        //reset value
        board[i][j]=temp;
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0){
            return false;
        }
        
        for(int i=0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[0] && dfs(board, i,j, 0,word)){
                  return true;
                }
            }
        }
        return false;
    }
};