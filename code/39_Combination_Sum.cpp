#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void comb(auto it, int count, int& sum, const int& target, vector<int>& path, vector<vector<int>>& paths) {

        // 剪枝条件：求和溢出
        if(sum > target) return;
        // 终止条件：求和相等
        else if(sum == target) paths.push_back(path);
        // 递归条件：放入一个数，然后继续选
        else {
            for(int i = 0; i < count; i++) {
                const auto& candidate = *(it+i);
                path.push_back(candidate);
                sum += candidate;
                comb(it + i, count - i, sum, target, path, paths);
                path.pop_back();
                sum -= candidate;
            }
        }
    }
    
    vector<vector<int>> combinationSum(const vector<int>& candidates, const int& target) {

        vector<vector<int>> paths;
        vector<int> path;
        int sum = 0;

        comb(candidates.begin(), candidates.size(), sum, target, path, paths);

        return paths;

    }
};

int main() {
    vector<int> candidates = {2,3,6,7};
    // vector<int>::iterator it = candidates.begin();
    for(auto& nums : Solution().combinationSum(candidates, 7)) {
        for(auto& num : nums) cout << num;
        cout << endl;
    }

}