#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        // 统计水量
        int water = 0;
        
        //建立下标堆栈
        stack<int> st;

        for(int i = 0; i < height.size(); i++) {

            // 弹出并计算积水
            while(!st.empty() && height[st.top()] < height[i]) {
                // 记录水层底高
                int heightBottom = height[st.top()];
                st.pop();
                // 如果左侧有更高的，计算水层
                if(!st.empty()) {
                    int heightWater = min(height[st.top()], height[i]) - heightBottom;
                    water += heightWater * (i - st.top() - 1);
                }
            }
            
            // 入栈
            st.push(i);
        }

        return water;
    }
};

int main() {
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};

    // for(auto& num : Solution().trap(nums)) cout << num ;
    // cout << endl;
    cout << Solution().trap(nums) << endl;
}