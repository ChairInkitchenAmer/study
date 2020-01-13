#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
       int min =INT_MAX;
       int mx =0;
        
        for(int i=0; i< prices.size(); i++){
            if(prices[i] < min){
                min = prices[i];
            } else {
                mx = max(mx,prices[i]-min);
            }
        }
        
        return mx;
    }
};