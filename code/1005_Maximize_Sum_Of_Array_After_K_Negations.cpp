#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        // 计数+范围遍历O(n) 替代排序O(nlogn)
        unordered_map<int, int> m;
        int sum = 0;
        for(const auto& num : nums) {
            m[num]++;
            sum += num;
        }

        // 遍历翻转，到第一个非负数/反转次数用完
        for(int num = -100; num <= 100; num++) {
            
            // 表里有的才处理
            if(m[num] != 0) {
                // 非负数：剩余K为奇数则反转一次，否则不变
                if(num >= 0) {
                    // 循环结束，不再对map/k做多余修改
                    if(k % 2 != 0) sum -= 2 * num;
                    break;
                }
                else {
                    // 次数用完
                    if(m[num] >= k) {
                        sum -= 2 * k * num;
                        break;
                    }
                    // 反转，修改map和k(可能-num也会被修改)
                    else {
                        // sum
                        sum -= 2 * m[num] * num;
                        // k
                        k -= m[num];
                        // map
                        m[-num] += m[num];
                        m[num] = 0; // 可以不要
                    }
                }
            }
        }

        return sum;
    }
};


int main() {
    vector<int> nums = {3,-1,0,2};
    cout << Solution().largestSumAfterKNegations(nums, 3) << endl;

}