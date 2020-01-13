#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
 
        int sum=0;
        for(int i: nums){
            sum+=i;
        }
        
        int n = nums.size() + 1;
        return (n*(n-1)) /2 - sum;
        
    }
};


///Gausses law 

//Sum of all number in a range is a formulat of  (N * (N-1)) / 2 
//if we want to check if a number is missing we should be able to get the total sum with Gauses law
//then subtract it from our sum of numbers in teh list.  The difference of the two number is equal to the missing number


/// Add n0 +n1+ n+2 n+3 ... as our sum of numbers in the array
/// int n = nums.size()+1 because the last number is included
/// apply gauses law  (n * (n-1) )/2 
/// subtract sum from gauses law total. The diff is the missing number