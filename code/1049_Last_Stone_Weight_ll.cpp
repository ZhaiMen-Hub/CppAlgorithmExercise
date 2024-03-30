#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& nums) {
        int numType = nums.size();
        
        int sum = 0;
        int package;
        for(const auto& num : nums) sum += num;
        package = sum / 2; // ceil还是floor不影响，一组是ceil另一组就是floor
        vector<int> dp(package + 1, 0); // dp[0]

        for(int i = 0; i < numType; i++){
            for(int j = package; j >= nums[i]; j--) {
                // if(j - nums[i] >= 0) dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        return sum - 2 * dp.back(); // (sum - dp.back) - dp.back

    }
};

int main(){
    vector<int> nums = {2,7,4,1,8,1};
    cout << Solution().lastStoneWeightII(nums) << endl;
}