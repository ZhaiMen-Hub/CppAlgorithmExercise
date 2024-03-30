#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        // 遍历物品和重量
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int numsD[2] = {0, 0};
        for(const auto& str : strs) {
            // 计数
            for(const auto& c : str) numsD[c - '0']++;
            for(int j = m; j >= numsD[0]; j--) {
                for(int k = n; k >= numsD[1]; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - numsD[0]][k - numsD[1]] + 1);
                }
            }
            // 清空计数
            numsD[0] = 0;
            numsD[1] = 0;
        }

        return dp[m][n];

    }
};

int main(){
    // vector<int> nums = {2,7,4,1,8,1};
    vector<string> strs = {"10","0001","111001","1","0"};
    cout << Solution().findMaxForm(strs, 5, 3) << endl;
}