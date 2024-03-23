#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    static bool cmp (const vector<int>& left, const vector<int>& right) {
        return left[1] < right[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& points) {

        sort(points.begin(), points.end(), cmp);

        // 遍历所有区间 (for - continue)
        int rightBound; // 循环里再初始化
        int count = 0;
        for(const auto& seg : points) {

            // 包含跳过
            // 第一区间(初始化rightBound) / 没包含：纳入 + 更新边界
            if(count == 0 || seg[0] >= rightBound) {
                count++;
                rightBound = seg[1];
            }

        }

        return points.size() - count;
    }
};


int main() {
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << Solution().eraseOverlapIntervals(intervals) << endl;

}