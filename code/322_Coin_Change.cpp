#include<iostream>
#include<vector>

using namespace std;

// class Solution {
// public:
//     int coinChange(vector<int>& nums, int amount) {
//         int numType = nums.size();
        
//         vector<unsigned long long> dp(amount + 1, INT_MAX);
//         dp[0] = {0}; // dp[0][0]

//         for(int i = 0; i < numType; i++){
//             for(int j = nums[i]; j <= amount; j++) {
//                 dp[j] = min(dp[j], dp[j - nums[i]] + 1);
//             }
//         }

//         if(dp.back() != INT_MAX) return dp.back(); 
//         else return -1;

//     }
// };

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int numType = coins.size();
        vector<int> dp(amount + 1, amount + 1); // dp[-1][0] = 0, dp[-1][] = amount / 1 + 1
        dp[0] = 0;

        // 完全背包
        for(int i = 0; i < numType; i++) {
            for(int j = coins[i]; j <= amount; j++){
                // dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]] + 1)
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        if(dp.back() == amount + 1) return -1;
        else return dp.back();
    }
};

int main(){
    vector<int> nums = {1,2,5};
    cout << Solution().coinChange(nums, 11) << endl;
}