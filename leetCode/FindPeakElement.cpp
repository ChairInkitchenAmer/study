#include <vector>

using namespace std;

class Solution1Better {
public:
    int search(vector<int>& nums, int l, int r){
        if(l==r)
            return l;
        
        int mid = (l+r)/2;
        if(nums[mid] > nums[mid + 1]){
            return search(nums,l,mid);
        }
        return search(nums, mid+1, r);
    }
    
    
    int findPeakElement(vector<int>& nums) {
        return search(nums, 0, nums.size()-1);
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        for(int i =0; i < nums.size();i++){
            if(i > 0 && i < nums.size()-1){
                if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                    return i;
                } 
            } else if(i > 0){
                if(nums[i] > nums[i-1]){
                     return i;
                }
            } else if(i < nums.size()-1){
                    if(nums[i] > nums [i+1]){
                        return i;
                    }
            } 
        }
        return 0;
    }
};