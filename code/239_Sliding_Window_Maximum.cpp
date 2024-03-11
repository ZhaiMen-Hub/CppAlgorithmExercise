#include <stack>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    
    // 单调队列
    class OrderedQueue {
    public: 
        
        deque<int> q;

        void push(int x) {
            // 从back删除小于x的元素
            while(q.size() != 0 && q.back() < x) q.pop_back();
            // push(x)
            q.push_back(x);
        }
        
        void pop(int x) {
            // 如果x是front（还在列表里）就移除
            if(q.front() == x) q.pop_front();
        }

        int front() {
            return q.front();
        }

    };
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 建立结果表
        vector<int> result(nums.size() - k + 1);

        // 滑动窗口单调队列
        OrderedQueue q;
        for(int i = 0; i < nums.size(); i++) {
            
            // 加入滑窗
            q.push(nums[i]);
            
            // 移出
            if(i >= k) q.pop(nums[i-k]);

            // 记录
            if(i >= k-1) result[i-k+1] = q.front();

        }

        return result;

    }
};

int main() {
    vector<int>nums = {1,3,-1,-3,5,3,6,7};
    for (auto num : Solution().maxSlidingWindow(nums, 3)) cout << num << endl;
}