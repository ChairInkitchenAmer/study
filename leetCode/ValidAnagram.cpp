using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        
        if(s.length() == 0){
            return true;
        }
        
        int counts[26] = {0};
                
        for(char a : s){
            counts[(int)a - 'a']++;
            counts[(int) a - 'a']--;
        }
        
        for(int a : counts){
            if(a!=0){
                return false;
            }
        }
        
        return true;
        
    }
};


/// Count the number of characters in s
///count the number of characters in t, by subtracting from the counts
//if  the count is not zero, then that means there were extras in T