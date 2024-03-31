#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        vector<int> heightsNew(heights.size() + 2, 0);
        for(int i = 0; i < heights.size(); i++) heightsNew[i + 1] = heights[i];

        int maxArea = 0;
        stack<int> st;
        for(int i = 0; i < heightsNew.size(); i++) {
            while(!st.empty() && heightsNew[st.top()] > heightsNew[i]) {
                int height = heightsNew[st.top()];
                st.pop();

                // 第一个元素为哨兵0，st不可能为空
                // 计算当前高度的最大矩形
                int area = (i - st.top() - 1) * height;
                if(area > maxArea) maxArea = area;
            }
            st.push(i);
        }
        return maxArea;
    }
};

int main() {
    vector<int> nums = {2,1,5,6,2,3};

    // for(auto& num : Solution().trap(nums)) cout << num ;
    // cout << endl;    
    cout << Solution().largestRectangleArea(nums) << endl;
}