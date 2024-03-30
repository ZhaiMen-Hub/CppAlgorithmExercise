#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {

        int dp[2] = {1, 1}; // 兼容初始化
        int swap;

        // 计算dp[n]需要dp[n-1]次
        for(int i = 0; i < n - 1; i++) {
            swap = dp[1];
            dp[1] += dp[0];
            dp[0] = swap;
        }

        return dp[1];
    }
};


int main() {
    cout << Solution().climbStairs(3) << endl;
}