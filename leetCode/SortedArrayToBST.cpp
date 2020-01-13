#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode * createBST(vector<int>& nums, int left, int right){
        if(left > right){
            return nullptr;
        }
        
        int mid = left + (right - left) /2;
        
        TreeNode * current = new TreeNode(nums[mid]);
        
        current->left = createBST(nums, left, mid-1);
        current->right= createBST(nums, mid+1, right);
            
        return current;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return nullptr;
        }
        return createBST(nums, 0, nums.size()-1);
    }
};