#include<vector>

using namespace std;

// DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // 状态: 日期x是否持有 最大利润
        // 兼容初始化：-1天买入等价于第一天持有，利润为-price[0]
        vector<int> dp{0, - prices[0], 0, - prices[0], 0};

        // 状态转移：sell0 => buy1 => sell1 => buy2 => sell2 四种情况
        // 没有交叉更新，不需要临时变量
        for(int i = 0; i < prices.size(); i++) {

            dp[4] = max(dp[4], dp[3] + prices[i]);
            dp[3] = max(dp[3], dp[2] - prices[i]);
            dp[2] = max(dp[2], dp[1] + prices[i]);
            dp[1] = max(dp[1], dp[0] - prices[i]);
            
        }

        return dp[4];
    }
};