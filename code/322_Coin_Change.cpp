#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& nums, int amount) {
        int numType = nums.size();
        
        vector<unsigned long long> dp(amount + 1, INT_MAX);
        dp[0] = {0}; // dp[0][0]

        for(int i = 0; i < numType; i++){
            for(int j = nums[i]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - nums[i]] + 1);
            }
        }

        if(dp.back() != INT_MAX) return dp.back(); 
        else return -1;

    }
};

int main(){
    vector<int> nums = {1,2,5};
    cout << Solution().coinChange(nums, 11) << endl;
}