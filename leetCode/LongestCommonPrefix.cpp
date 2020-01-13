#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        
        int j = 0;
        bool run=true;
        while(run){
            if(j < strs[0].length()){ 
                char letter = strs[0][j];
                //check each word at that letter
                for(int i = 1; i < strs.size(); i++){
                    if(letter != strs[i][j]){
                        run=false;
                        j--;
                        break;
                    }
                }      
                
                j++; //advance the letter
            } else {
                run=false;
            }
        }
        
        if(j==0){
            return "";
        }
        
        return strs[0].substr(0,j);
    }
};