class Solution {
public:
    bool judgeCircle(string moves) {
        
        int up=0, left=0;
        for(char move : moves){
            if(move == 'L'){
                left--;
            } else if (move == 'U'){
                up++;
            } else if (move == 'R'){
                left++;
            } else if( move == 'D'){
                up--;
            }
        }
        return up == 0 && left ==0;
    }
};