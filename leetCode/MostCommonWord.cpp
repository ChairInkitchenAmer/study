#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        if(paragraph.length() == 0){ return ""; }
        
        unordered_set<string> bannedMap;
        unordered_map<string, int> words;
        
        for(string word : banned){
            bannedMap.insert(word);
        }
        
        transform(paragraph.begin(), paragraph.end(), paragraph.begin() ,::tolower);

        int i=0;
        string currentWord="";
        while( i <= paragraph.length()){
           if(isalpha(paragraph[i])){ //is it a letter?
               currentWord += paragraph[i];
           } else if(currentWord.length() > 0) { //punctuation
               if(bannedMap.find(currentWord) == bannedMap.end()){
                    if(words.find(currentWord) == words.end()){
                        words[currentWord]=1;
                    } else {
                        words[currentWord]++;
                    }
               }
               currentWord = "";
           }
           i++;
        }

        int max = 0;
        string word;
        for(auto w : words){
            if(w.second > max){
                max= w.second;
                word =  w.first;
            }
        }
        
        return word;
    }
};