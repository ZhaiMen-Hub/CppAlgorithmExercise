#include<vector>
#include<algorithm>
#include<iostream>


using namespace std;


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        // <2个剪枝
        if(nums.size() <= 1) return nums.size();
        // 至少有2个
        else {
            int preDiff = 0; // 只有初始时preDiff=0
            int curDiff = 0;
            int wiggle = 0;
            for(int i = 1; i < nums.size(); i++) {
                curDiff = nums[i] - nums[i - 1];
                if(preDiff <= 0 && curDiff > 0 || preDiff >= 0 && curDiff < 0) {
                    preDiff = curDiff;
                    wiggle++;
                }
            }
            return wiggle + 1;

        }
    }
};

int main() {
    vector<int> nums = {1,7,4,9,2,5};
    cout << Solution().wiggleMaxLength(nums) << endl;

}