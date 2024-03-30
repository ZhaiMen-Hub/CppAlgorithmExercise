#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        
        // 因为0和1都要，要记录
        // 下标范围: [0, n+1]
        int n = cost.size();
        vector<int> minCost(n + 2, 0);    // 兼容初始化, minCost[n] = minCost[n+1] = 0

        for(int i = n - 1; i >= 0; i--) minCost[i] = cost[i] + min(minCost[i + 1], minCost[i + 2]);

        return min(minCost[0], minCost[1]);
    }
};


int main() {
    vector<int> nums = {1,100,1,1,1,100,1,1,100,1};
    cout << Solution().minCostClimbingStairs(nums) << endl;
}