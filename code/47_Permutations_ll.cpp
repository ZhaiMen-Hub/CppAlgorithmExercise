#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void backtrack(const vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& paths) {
        // 终止条件 path.size = nums.size
        if(path.size() == nums.size()) paths.push_back(path);
        // 递归条件：选一个没用过且没占位的数，记录哈希表&置位used，然后递归
        else {
            unordered_set<int> s;
            for(int i = 0; i < nums.size(); i++) {
                // 只选没占用的
                if(!used[i] && s.find(nums[i]) == s.end()) {
                    
                    path.push_back(nums[i]);
                    // 占用置位(数值去重，需要回溯)
                    used[i] = true;
                    // 使用记录(树层去重，不需要回溯)
                    s.insert(nums[i]);

                    backtrack(nums, used, path, paths);
                    
                    path.pop_back();
                    used[i] = false;
                    
                }
            }

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> paths;
        vector<int> path;
        vector<bool> used(nums.size());

        backtrack(nums, used, path, paths);
        
        return paths;
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    // for(auto& strs : Solution().subsets("25525511135")) cout << strs << endl;

    for(auto& strs : Solution().permuteUnique(nums)) {
        for(auto& str : strs) cout << str;
        cout << endl;
    }
}