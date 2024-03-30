#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        // 计算 sumP
        int sumP, sum = 0;
        for(const auto& num : nums) sum += num;
        if((sum + target) % 2 == 1 || abs(target) > sum) return 0;
        else sumP = (sum + target) / 2;

        vector<int> dp(sumP + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = sumP; j >= nums[i]; j --) {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp.back();

    }
};

int main(){
    // vector<int> nums = {2,7,4,1,8,1};
    vector<int> nums(5, 1);
    cout << Solution().findTargetSumWays(nums, 3) << endl;
}