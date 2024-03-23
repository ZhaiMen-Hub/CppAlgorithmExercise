#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& left, const vector<int>& right) {
        return left[0] < right[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), cmp);


        vector<vector<int>> result = {intervals[0]};
        for(const auto& interval : intervals) {
            
            auto& bound = result.back();
            // 不重叠：pushback
            if(interval[0] > bound[1]) result.push_back(interval);
            // 重叠：更新右边界
            else if(interval[1] > bound[1]) bound[1] = interval[1];
            
        }


        return result;
    }
};

// // 要添加最后一组
// class Solution {
// public:
//     static bool cmp(const vector<int>& left, const vector<int>& right) {
//         return left[0] < right[0];
//     }

//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
//         sort(intervals.begin(), intervals.end(), cmp);

//         int rightBound = intervals[0][1]; // 兼容初始化
//         int leftBound = intervals[0][0]; // 兼容初始化
//         vector<vector<int>> result;
//         for(const auto& interval : intervals) {
            
//             // 不重叠：pushback并重置左右边界
//             if(interval[0] > rightBound) {
//                 result.push_back(vector<int>{leftBound, rightBound});
//                 leftBound = interval[0];
//                 rightBound = interval[1];
//             }
//             // 重叠：更新右边界
//             else {
//                 if(interval[1] > rightBound) rightBound = interval[1];
//             }

//         }
//         // 添加最后一组
//         result.push_back(vector<int>{leftBound, rightBound});

//         return result;
//     }
// };


int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    for(auto nums : Solution().merge(intervals)) for(auto num : nums) cout << num << endl;

}