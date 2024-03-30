#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        int maxLen = 0;
        for(int i = nums1.size() - 1; i >= 0; i--) {
            for(int j = nums2.size() - 1; j >= 0; j--) {
                if( nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    if(dp[i][j] > maxLen) maxLen = dp[i][j];
                }
                else {
                    dp[i][j] = 0;
                }
                
            }
        }
        return maxLen;
    }
};

// 测试
int main() {
    
    vector<int> A = {1,2,3,2,1};
    vector<int> B = {3,2,1,4,7};
    
    cout << Solution().findLength(A, B) << endl;

}