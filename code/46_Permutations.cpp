#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void backtrack(const vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& paths) {
        // 终止条件 path.size = nums.size
        if(path.size() == nums.size()) paths.push_back(path);
        // 递归条件：选一个没用过的数，置位used，然后递归
        else {
            for(int i = 0; i < nums.size(); i++) {
                // 只选没占用的
                if(!used[i]) {
                    // 占用置位
                    path.push_back(nums[i]);
                    used[i] = true;
                    backtrack(nums, used, path, paths);
                    path.pop_back();
                    used[i] = false;
                }
            }

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> paths;
        vector<int> path;
        vector<bool> used(nums.size());

        backtrack(nums, used, path, paths);
        
        return paths;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    // for(auto& strs : Solution().subsets("25525511135")) cout << strs << endl;

    for(auto& strs : Solution().permute(nums)) {
        for(auto& str : strs) cout << str;
        cout << endl;
    }
}