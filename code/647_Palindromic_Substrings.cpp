#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {

        // dp[i][j]表示[i, j]是否为回文子串
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int count = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            for(int j = i; j < s.size(); j++) {
                if(s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    count++;
                }
                // else dp[i][j] = false;
            }
        }

        return count;

    }
};

// 测试
int main() {
    
    // vector<int> nums1 = {1,4,2};
    // vector<int> nums2 = {1,2,4};
    
    // cout << Solution().countSubstrings("fdsklf") << endl;
    cout << Solution().countSubstrings("aaa") << endl;

}