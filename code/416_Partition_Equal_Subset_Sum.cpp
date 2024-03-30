#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int numType = nums.size();
        
        int sum = 0;
        int package;
        for(const auto& num : nums) sum += num;
        if(sum % 2 == 1) return false;
        else package = sum / 2;

        vector<int> dp(package + 1, 0); // dp[0]

        for(int i = 0; i < numType; i++){
            for(int j = package; j >= 0; j--) {
                if(j - nums[i] >= 0) dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        if(dp.back() != package) return false;
        else return true;

    }
};

int main(){
    vector<int> nums = {1,5,11,5};
    cout << Solution().canPartition(nums) << endl;
}