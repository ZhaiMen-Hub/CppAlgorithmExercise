

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxNums(nums.size()), minNums(nums.size());
        maxNums[0] = nums[0]; // 剪枝初始化
        minNums[0] = nums[0];
        int maxCur = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            maxNums[i] = max(nums[i], max(maxNums[i-1] * nums[i], minNums[i-1] * nums[i]));
            minNums[i] = min(nums[i], min(maxNums[i-1] * nums[i], minNums[i-1] * nums[i]));
            
            if(maxNums[i] > maxCur) maxCur = maxNums[i];
        }
        return maxCur;
    }
};