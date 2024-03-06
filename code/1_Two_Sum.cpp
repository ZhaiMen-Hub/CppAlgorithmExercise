
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // iterate and map
        int len = nums.size();
        unordered_map<int,int> hash_map;
        // vector<int> result;
        for (int i = 0; i < len; i++) {
            if (hash_map.find(target - nums[i]) != hash_map.end()) 
                return vector<int>{hash_map[target - nums[i]], i}; 
            else
                hash_map[nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};

// testing
int main() {
    vector<int> nums = {3,2,4};
    int target = 6;
    
    for (int num : Solution().twoSum(nums, target)) cout << num << endl;

}