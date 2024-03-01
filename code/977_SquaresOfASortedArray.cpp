
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int size = nums.size();
        vector<int> result(size);
        int left = 0;
        int right = size - 1;

        for (int i = size - 1; i >= 0; i--) {
            
            int num_left = nums[left];
            int num_right = nums[right];
            int left_square = num_left * num_left;
            int right_square = num_right * num_right;
            
            if (left_square > right_square) {
                result[i] = left_square;
                left++;
                // num_left = nums[left];               //  最后会下标越界
                // left_square = num_left * num_left;
            }
            else {
                result[i] = right_square;
                right--;
                // num_right = nums[right];
                // right_square = num_right * num_right;
            }
        }
        return result;

    }
};


// testing
int main() {
    // vector<int> nums = {-4,-1,0,3,10};
    vector<int> nums = {1};
    
    for (int num : Solution().sortedSquares(nums)) cout << num << " ";
    cout << endl;

}