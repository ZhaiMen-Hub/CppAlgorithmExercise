#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // 创建结果变量
        vector<vector<int>> result;

        // 排序
        sort(nums.begin(), nums.end());

        // 迭代a (最后剩下两个且nums[itA]<=0)
        int itA = 0;
        while (itA <= nums.size() - 2 && nums[itA] <= 0) {

            int itB = itA + 1;
            int itC = nums.size() - 1;
            
            // 双指针迭代 B 和 C
            while( itB < itC )
            {

                // 如果满足要求，加入结果，否则调整 itB 和 itC
                if (nums[itA] + nums[itB] + nums[itC] < 0) itB++;
                else if (nums[itA] + nums[itB] + nums[itC] > 0) itC--;
                else if (nums[itA] + nums[itB] + nums[itC] == 0) {
                    result.push_back(vector<int>{nums[itA], nums[itB], nums[itC]});
                    itB++;
                    itC--;
                }

                // 相同的数，B只用最左边（除A以外），C只用最右边(数组下标和itB/itC不要越界)
                while (itB > itA + 1 && itB < nums.size() - 1 && nums[itB - 1] == nums[itB]) itB++;
                while (itC >= 1 && itC < nums.size() - 1 && nums[itC + 1] == nums[itC]) itC--;
                
            }

            // 移动A，且A只用最左边
            itA++;
            while (itA >= 1 && itA < nums.size() - 1 && nums[itA - 1] == nums[itA]) itA++;

        }

        // 返回结果变量
        return result;
    }
};

// testing
int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    for (auto num_vec : Solution().threeSum(nums)) {
        for(auto num : num_vec) {
            cout << num;
        }
        cout << endl;
    }
    // cout << Solution().fourSumCount(nums1, nums2, nums3, nums4) << endl;

}