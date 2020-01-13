  #include <vector>

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int index = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != 0) {
			nums[index++] = nums[i];
		}
	}

	for (int i =index; i < nums.size(); i++) {
		nums[i] = 0;
	}
    }
};

///ALSO SEEMS LIKE MOVING FORWARD IN LOOP IS FASTER 

  /// The big solution here:  Only keep track of items that are non Zero
  // Index = 0
  // if its a non zero integer
  // keep it, up the index
  // loop until end

  //finally just add zeros to the end. (no need to move in place or sort)