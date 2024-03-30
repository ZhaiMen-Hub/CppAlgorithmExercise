#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int dp[2] = {0, 0}; // dp[-2], dp[-1]

        for(const auto& num : nums) {
            int rob = max(dp[1], dp[0] + num);
            dp[0] = dp[1];
            dp[1] = rob;
        }

        return dp[1];
    }
};

int main() {
    vector<int> nums = {2,7,9,3,1};
    cout << Solution().rob(nums) << endl;
}