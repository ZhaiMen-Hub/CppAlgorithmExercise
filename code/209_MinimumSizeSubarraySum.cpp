
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
        int i = 0;
        int sum = 0;
        for (int j = 0; j < nums.size(); j++){

            // j++
            sum += nums[j];
            // i++
            while(sum >= target){
                if (result > j - i + 1) result = j - i + 1; //  更新前要比较
                sum -= nums[i];
                i++;

            }

            // i++
        }

        return result == INT_MAX ? 0 : result;
    }
};


// testing
int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    
    cout << Solution().minSubArrayLen(target, nums) << endl;

}