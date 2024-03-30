#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // 兼容初始化 price[-1] = price[0]
        int maxDiff = 0; // price[0] - price[-1]
        int minI = prices[0]; // price[-1]  

        for(const auto& price : prices) {
            maxDiff = max(maxDiff, price - minI);
            minI = min(minI, price);
        }

        return maxDiff;
    }
};

int main() {
    vector<int> nums = {7,1,5,3,6,4};
    cout << Solution().maxProfit(nums) << endl;
}