#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {

        // 0个节点也是一种情况，兼容初始化
        vector<int> dp(n + 1, 1);

        // dp[0] 和 dp[1] 已经兼容初始化，从2开始
        for(int i = 2; i <= n; i++) {
            // 一侧节点范围为[0, i-1]
            int sum = 0;
            for(int j = 0; j < i; j++) {
                // 左侧j个，右侧i-j-1个
                sum += dp[j] * dp[i - j - 1];
            }
            dp[i] = sum;
        }

        return dp[n];

    }
};

int main() {
    // vector<int> nums = {1,100,1,1,1,100,1,1,100,1};
    // vector<vector<int>> obstacleGrid(3, vector<int>(3, 0));
    // obstacleGrid[1][1] = 1;
    cout << Solution().numTrees(3) << endl;
}