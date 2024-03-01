#include <iostream>
#include <vector>

using namespace std;

// editing
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1 ; // 闭区间
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target) return middle;
            else {
                if (nums[middle] < target) left = middle + 1;
                else if (nums[middle] > target) right = middle - 1;
                else cout << "running error" << endl;
            }
                
        }

        return -1;

    }
};


// testing
int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;

    cout << Solution().search(nums, target) << endl;
}