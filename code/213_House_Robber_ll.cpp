#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        // 剪枝：只有一个
        if(nums.size() == 1) return nums[0];

        int dpF[2] = {0, 0}; // dp[-2], dp[-1]
        int dpB[2] = {0, 0};
        
        for(int i = 1; i < nums.size(); i++) {

            // 考虑最后一个（不考虑第一个）
            int rob = max(dpB[1], dpB[0] + nums[i-1]);
            dpB[0] = dpB[1];
            dpB[1] = rob;

            // 考虑第一个（不考虑最后一个）
            rob = max(dpF[1], dpF[0] + nums[i]);
            dpF[0] = dpF[1];
            dpF[1] = rob;
        }

        return max(dpF[1], dpB[1]);
    }
};

int main() {
    vector<int> nums = {1,2,3,1};
    cout << Solution().rob(nums) << endl;
}