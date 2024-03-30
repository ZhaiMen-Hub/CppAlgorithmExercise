#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // 兼容初始化 dp[-1] = 0
        vector<int> dp(nums.size() + 1, 0);

        int maxI = 0; // dp[-1]
        // i 是 nums 的 index
        for(int i = 0; i < nums.size(); i++) {
            
            // 前面的最大长度
            int maxJ = 0;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) maxJ = max(maxJ, dp[j + 1]);
            }
            dp[i + 1] = maxJ + 1;
            maxI = max(maxI, dp[i + 1]);
        }

        return maxI;

    }
};

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << Solution().lengthOfLIS(nums) << endl;
}