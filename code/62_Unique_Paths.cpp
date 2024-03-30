#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // m = 0 和 n = 0 已经初始化为1了
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};


int main() {
    // vector<int> nums = {1,100,1,1,1,100,1,1,100,1};
    cout << Solution().uniquePaths(3, 7) << endl;
}