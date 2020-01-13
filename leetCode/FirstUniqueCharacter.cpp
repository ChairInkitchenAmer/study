#include <unordered_map>
#include <math.h>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
         unordered_map<char,int> map;
        
        for(int i=0; i < s.length();i++){
            char a = s[i];
            if(map.find(a) == map.end()){
                map[a]=i;
            }
            else {
                map[a]=-1;
            }
        }
        
        int index= INT_MAX;
        for(auto val : map){
             if(val.second != -1 && val.second < index){
                    index= val.second;
             }
        }
        
        return index == INT_MAX ? -1 : index;
    }
};