#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        // 和为0的4-tuple数量
        int result = 0;
        
        // 构造哈希表：和-次数
        unordered_map<long,int> hash;
        // 计数哈希表
        for (const int& num3 : nums3) {
            for (const int& num4 : nums4) {
                // 相应的和的计数器+1
                hash[num3 + num4]++;
            }
        }

        // 遍历nums1, nums2；计算匹配
        for (const int& num1 : nums1) {
            for (const int& num2 : nums2) {
                result += hash[-num1-num2];
            }
        }

        return result;

    }
};

// testing
int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};
    
    // for (int num : Solution().fourSumCount(nums1, nums2, nums3, nums4)) cout << num << endl;
    cout << Solution().fourSumCount(nums1, nums2, nums3, nums4) << endl;

}