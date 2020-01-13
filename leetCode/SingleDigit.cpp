#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        if(nums.size()==0){
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        int i=0;
        for(i; i< nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                i++;
            } else {   
              break;
            }
        }
        return nums[i];
    }
};

///better solution:

class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        
        if(nums.size()==0){
            return 0;
        }
        
        int sum =0;
        for(int& num : nums){
            sum ^= num;    
        }
     
    return sum;
    }
};