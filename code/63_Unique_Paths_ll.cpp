#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // 有障碍，不能初始化为1
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                // else if(i == 0 && i < m - 1 || j == 0 && j < n - 1) dp[i][j] = 1;
                // else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else if(i == 0 && j == 0) dp[i][j] = 1;
                else {
                    // dp 初始化为0
                    if(i > 0) dp[i][j] += dp[i - 1][j];
                    if(j > 0) dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];

    }
};


int main() {
    // vector<int> nums = {1,100,1,1,1,100,1,1,100,1};
    vector<vector<int>> obstacleGrid(3, vector<int>(3, 0));
    obstacleGrid[1][1] = 1;
    cout << Solution().uniquePathsWithObstacles(obstacleGrid) << endl;
}