#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        // dp[i][j]表示[i, j]是否为回文子串
        vector<vector<int>> dp(s.size() , vector<int>(s.size() , 0));
        int maxLen = 1;
        // dp[i][j]对应[i,j]
        for(int i = s.size() - 1; i >= 0; i--) {
            dp[i][i] = 1; // 单独处理 i = j的情况
            for(int j = i + 1; j < s.size(); j++) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    if(dp[i][j] > maxLen) maxLen = dp[i][j];
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
                
            }
        }

        return maxLen;

    }
};

// 测试
int main() {
    
    // vector<int> nums1 = {1,4,2};
    // vector<int> nums2 = {1,2,4};
    
    cout << Solution().longestPalindromeSubseq("bbbab") << endl;

}