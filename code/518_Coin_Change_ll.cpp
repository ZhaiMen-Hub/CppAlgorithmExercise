#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& nums) {
        int numType = nums.size();
        
        vector<int> dp(amount + 1);
        dp[0] = {1}; // dp[0][0]

        for(int i = 0; i < numType; i++){
            for(int j = nums[i]; j <= amount; j++) {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp.back(); 

    }
};

int main(){
    vector<int> nums = {1,2,5};
    cout << Solution().change(5, nums) << endl;
}