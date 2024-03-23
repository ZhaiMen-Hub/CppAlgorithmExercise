#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        // 能套利就套利
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};


int main() {
    vector<int> nums = {7,1,5,3,6,40};
    cout << Solution().maxProfit(nums) << endl;

}