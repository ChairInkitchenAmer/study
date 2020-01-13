#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> t_stack;
        stack<char> s_stack;
        
        for(int i=0; i < S.length(); i++){
            if(S[i] == '#'){
               if(!s_stack.empty()){
                  s_stack.pop();
               }
            } else {
                s_stack.push(S[i]);
            }
        }
        
        for(int i=0; i < T.length(); i++){
            if(T[i] == '#'){
                if(!t_stack.empty()){
                    t_stack.pop();
                }
            } else {
                t_stack.push(T[i]);
            }
        }
        
        
        if(t_stack.size() != s_stack.size()){
            return false;
        }
           
        while(!s_stack.empty()){
            if(s_stack.top() != t_stack.top()){
                return false;
            }
            
            s_stack.pop();
            t_stack.pop();
        }
           
        return true;
    }
};