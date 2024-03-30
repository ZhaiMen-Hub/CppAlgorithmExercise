#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        // 长度至少为1，不用剪枝

        // 预处理index = 0, dp[0] = 1
        vector<int> dp(nums.size(), 1);
        int maxLen = dp[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1; // else = 1
                if(dp[i] > maxLen) maxLen = dp[i];
            }
            
        }
        
        return maxLen;
    }
};

int main() {
    vector<int> nums = {1,3,5,4,7};
    cout << Solution().findLengthOfLCIS(nums) << endl;
}