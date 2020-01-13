#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        if(nums.size() == 1){
            return nums[0];
        }
        
        for(int i=0; i < nums.size(); i++){
        
            auto item = map.find(nums[i]);
            if(item != map.end() && item->second +1 > nums.size()/2){
                return item->first;
            } else {
                    map[nums[i]]++;

            }
        }
    
        return -1;
    }
};

class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
    
        sort(nums.begin(), nums.end());
        
        int lastValue=0;
        int lastCount=0;
        for(int i=0; i< nums.size(); i++){
            if(nums[i]== lastValue){
                lastCount++;                
            } else{
                lastValue=nums[i];
                lastCount=1;
            }
            
            if(lastCount >  nums.size() / 2){
                return lastValue;
            }
        }
        
    
        return -1;
    }
};