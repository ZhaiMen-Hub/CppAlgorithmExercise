#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 剪枝
        if(nums.size() == 1) return true;
        // size >= 2
        else {
            // 初始最大范围（下标)
            int maxDist = 0;
            for(int i = 0; i < nums.size() && i <= maxDist; i++) {
                // 终止条件: 到达终点
                if (i == nums.size() - 1) return true;
                else {
                    // 更新maxDist
                    int curDist = i + nums[i];
                    if(curDist > maxDist) maxDist = curDist;
                }
            }
            // 没到达终点就因为i <= maxDist退出
            return false;
        }
    }
};


int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << Solution().canJump(nums) << endl;

}