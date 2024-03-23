#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int Aj = 0;     // A[-1]
        int minA = 0;   // A[-1]
        int maxDiff = nums[0]; // A[0] - A[-1], 是maxSub的一个可能结果
        // A[i] A[j] => sum a[i+1] a[j]
        int minIndex = 0; // i+1
        pair<int,int> maxSeg = {0, 0};
        // 迭代A[j], 更新minA和maxDiff
        for(int j = 0; j < nums.size(); j++) {
            Aj += nums[j];
            // maxDiff
            const int curDiff = Aj - minA;
            if(curDiff > maxDiff) {
                maxDiff = curDiff;
                maxSeg.first = minIndex;
                maxSeg.second = j;
            }
            // minA (i<j, 要在maxDiff后更新)
            if(Aj < minA) {
                minA = Aj;
                minIndex = j + 1;
            }
        }

        cout << maxSeg.first << maxSeg.second << endl;
        return maxDiff;
    }
};

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution().maxSubArray(nums) << endl;

}