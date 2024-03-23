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
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end(), cmp);

        // 遍历所有气球 (for - continue)
        // 初始右边界:最小
        int rightBound = INT_MIN; // 用不到
        int count = 0;
        for(const auto& seg : points) {

            // 射爆跳过
            // 第一箭 / 没射爆：加一箭，更新边界
            if(count == 0 || seg[0] > rightBound) {
                count++;
                rightBound = seg[1];
            }

        }

        return count;
    }
};


int main() {
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    cout << Solution().findMinArrowShots(points) << endl;

}