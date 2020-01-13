#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        
        for(int i : nums1){
            map[i]=1;
        }
        
        for(int i : nums2){
            if(map.find(i) != map.end()){
                map[i]--;
            }
        }
        
        vector<int> result;
        for(auto item : map){
            if(item.second <=0){
                result.push_back(item.first);
            }
        }
        
        return result;
    }
};