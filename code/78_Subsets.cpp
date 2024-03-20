#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void backtrack(vector<int>::iterator stIt, int count, vector<int>& path, vector<vector<int>>& paths) {
        
        // 每个节点都添加
        paths.push_back(path);
        
        // 终止条件: count = 0，已经到达叶子节点(空节点不入栈)
        // 不操作，隐去
        if(count) {
            for(int i = 0; i < count; i++) {
                
                path.push_back(*(stIt+i));

                backtrack(stIt + (i + 1), count - (i + 1), path, paths);

                path.pop_back();
            }
        }
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> paths;
        vector<int> path;

        backtrack(nums.begin(), nums.size(), path, paths);

        return paths;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    // for(auto& strs : Solution().subsets("25525511135")) cout << strs << endl;

    for(auto& strs : Solution().subsets(nums)) {
        for(auto& str : strs) cout << str;
        cout << endl;
    }
}