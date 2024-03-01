#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for (int num : nums){
            if (num != val){
                nums[index] = num;
                index++;
            }
        }
        return index;
    }
};


// testing
int main() {
    vector<int> nums = {3,2,2,3};
    int val = 3;
    
    cout << Solution().removeElement(nums, val) << endl;

}