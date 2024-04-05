#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
             
        // 兼容初始化为0
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        int maxLen = 0;
        for(int i = text1.size() - 1; i >= 0; i--) {
            for(int j = text2.size() - 1; j >= 0; j--) {
                if( text1[i] == text2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    if(dp[i][j] > maxLen) maxLen = dp[i][j];
                }
                else {
                    // 保持最大长度不变，注意不是dp[i+1][j+1]
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
                
            }
        }
        return maxLen;
        
    }
};

// 测试
int main() {
    
    // string haystack = "aabaabaafa";
    // string needle = "aabaaf";
    string text1 = "abcde", text2 = "ace";
    
    cout << Solution().longestCommonSubsequence(text1, text2) << endl;

}