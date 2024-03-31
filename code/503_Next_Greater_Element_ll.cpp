#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> rightIndex(nums.size(), -1);
        
        // find the index of the maximum
        int maxIndex = 0; // 兼容初始化
        for(int i = 1; i < nums.size(); i++) if(nums[i] > nums[maxIndex]) maxIndex = i;

        // 从maxIndex+1开始遍历
        stack<int> st;
        for(int i = 1; i <= nums.size(); i++) {

            // 循环索引
            int j = (i + maxIndex) % nums.size();

            // 添加索引并弹出
            while(!st.empty() && nums[st.top()] < nums[j]) {
                rightIndex[st.top()] = nums[j];
                st.pop();
            }
            // 添加
            st.push(j);
        }

        return rightIndex;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,3};

    for(auto& num : Solution().nextGreaterElements(nums)) cout << num ;
    cout << endl;
}