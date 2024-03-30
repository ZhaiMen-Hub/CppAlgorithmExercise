#include<iostream>
#include<vector>

using namespace std;

// 不剪枝
class Solution {
public:
    int integerBreak(int n) {

        // 下标i对应i的分解
        vector<int> dp(n + 1, 0);


        // 可以不再拆
        for(int i = 1; i <= n; i++) {
            int maxProd = 0; // 不干扰乘积比较
            for(int j = 1; j <= i - 1; j++) {
                maxProd = max(maxProd, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = maxProd;
        }

        return dp[n];

    }
};

int main() {
    // vector<int> nums = {1,100,1,1,1,100,1,1,100,1};
    // vector<vector<int>> obstacleGrid(3, vector<int>(3, 0));
    // obstacleGrid[1][1] = 1;
    cout << Solution().integerBreak(6) << endl;
}