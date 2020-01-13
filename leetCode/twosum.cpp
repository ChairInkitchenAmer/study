#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> values;
        for(int i=0;i<nums.size();i++){
            
            int test = target- nums[i];
           
                for(int o = i+1; o< nums.size(); o++){
                    if(nums[o]==test){
                        values.push_back(i);
                        values.push_back(o);
                        return values;
                    }
                }
            }
        
        return values;
    }
};