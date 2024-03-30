#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>

using namespace std;

// // 贪心：能套利就套利
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int profit = 0;
//         // 能套利就套利
//         for(int i = 1; i < prices.size(); i++) {
//             if(prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
//         }
//         return profit;
//     }
// };

// DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // 状态: 日期x是否持有 最大利润
        // 兼容初始化：-1天买入等价于第一天持有，利润为-price[0]
        vector<vector<int>> dp(prices.size() + 1, vector<int>{0, -prices[0]});

        // 状态转移：无/有 x 无/有 四种情况
        for(int i = 0; i < prices.size(); i++) {
            dp[i + 1][0] = max(dp[i][0], dp[i][1] + prices[i]);
            dp[i + 1][1] = max(dp[i][1], dp[i][0] - prices[i]);
        }

        return dp.back()[0];
    }
};

int main() {
    vector<int> nums = {7,1,5,3,6,40};
    cout << Solution().maxProfit(nums) << endl;

}