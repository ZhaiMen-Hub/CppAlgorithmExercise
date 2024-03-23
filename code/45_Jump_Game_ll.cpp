#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // 一定能到达
        // 剪枝
        if(nums.size() == 1) return 0;
        // size >= 2
        else {
            // 初始最大范围（下标)
            int maxDist = 0;
            int maxDistInI = 0; // 当前步内的最大
            int count = 0;
            // 到达 size-1即可退出循环
            for(int i = 0; i < nums.size() && i <= maxDist; i++) {
                
                // 更新maxDistInI
                int curDist = i + nums[i];
                if(curDist > maxDistInI) maxDistInI = curDist;

                // 到达边界，更新当前步
                // 当前步能到达，直接退出
                if(i == maxDist) {
                    count++;
                    maxDist = maxDistInI;
                    if(maxDist >= nums.size() - 1) break;
                }
                
            }
            return count;

        }
    }
};


int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << Solution().jump(nums) << endl;

}