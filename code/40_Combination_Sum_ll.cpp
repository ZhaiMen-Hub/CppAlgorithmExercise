#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void comb(const auto& can, auto it,int& sum, const int& target, vector<int>& path, vector<vector<int>>& paths) {

        // 终止条件：求和相等
        if(sum == target) paths.push_back(path);
        // 递归条件：放入一个数，然后继续选(知道用完所有数)
        // 从小到大，如果加入的数超过target了，跳过当前及后面的循环
        else {
            while(it != can.end() && sum + it->first <= target) {
                
                // cout << it->first << endl;
                // 循环条件和if条件保证 it.second 至少为 1
                it->second--;
                path.push_back(it->first);
                sum += it->first;

                // 用完这个数字就切换到下一个(不能改变原来循环的it,要用来回溯)
                if(!it->second) 
                    comb(can, it + 1, sum, target, path, paths);
                    // comb(can, next(it, 1), sum, target, path, paths);
                    // {
                    //     auto itNew = it;
                    //     comb(can, ++itNew, sum, target, path, paths);
                    // }
                else 
                    comb(can, it, sum, target, path, paths);

                it->second++;
                path.pop_back();
                sum -= it->first;

                it++; // 移动到下一个数

            }
        }
    }
    
    vector<vector<int>> combinationSum2(const vector<int>& candidates, const int& target) {

        // 统计
        unordered_map<int,int> m;
        for(const auto& c : candidates) m[c]++;
        // 排序
        map<int,int> mOrdered(m.begin(), m.end());
        // 转vector
        vector<pair<int,int>> can(mOrdered.begin(), mOrdered.end());
        
        vector<vector<int>> paths;
        vector<int> path;
        int sum = 0;

        comb(can, can.begin(), sum, target, path, paths);

        return paths;

    }
};

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    
    for(auto& nums : Solution().combinationSum2(candidates, 8)) {
        for(auto& num : nums) cout << num;
        cout << endl;
    }

}