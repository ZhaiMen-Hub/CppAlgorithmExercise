#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& text1, vector<int>& text2) {
             
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
    
    vector<int> nums1 = {1,4,2};
    vector<int> nums2 = {1,2,4};
    
    cout << Solution().maxUncrossedLines(nums1, nums2) << endl;

}