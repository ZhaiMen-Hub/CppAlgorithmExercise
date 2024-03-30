#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int numType = nums.size();
        
        vector<unsigned long long> dp(target + 1); // leetcode有一组测试，中间组合数非常大，但dp.back()只是int
        dp[0] = {1}; // dp[0][0]

        // 遍历容量
        for(int j = 0; j <= target; j++) {
            // 遍历物品
            for(int i = 0; i < numType; i++){
                if(j >= nums[i]) dp[j] += dp[j - nums[i]];
            }
        }

        return dp.back(); 

    }
};

int main(){
    vector<int> nums = {1,2,3};
    cout << Solution().combinationSum4(nums, 4) << endl;
}