#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void backtrack(vector<int>::iterator stIt, int count, vector<int>& path, vector<vector<int>>& paths) {
        
        // 第三层开始每个节点都添加（不满足要求的数不加入）
        if(path.size() >= 2) paths.push_back(path);
        
        // 终止条件: count = 0，已经到达叶子节点(空节点不入栈)
        // 不操作，隐去
        // 递归条件：选一个数，然后缩小范围继续选
        if(count) {
            // 哈希表记录用过的元素
            unordered_set<int> s;
            for(int i = 0; i < count; i++) {
                
                
                const int& cur = *(stIt+i);
                // 除了第一层，满足递增要求才递归（生成下一层节点）
                // 且每层每个数只能用一次
                if(s.find(cur) == s.end() && (!path.size() || cur >= path.back())) {
                    // 记录用过的
                    s.insert(cur);
                    
                    path.push_back(cur);

                    backtrack(stIt + (i + 1), count - (i + 1), path, paths);

                    path.pop_back();
                }
            }
        }
        
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {

        vector<vector<int>> paths;
        vector<int> path;

        backtrack(nums.begin(), nums.size(), path, paths);

        return paths;
    }
};

int main() {
    vector<int> nums = {4, 6, 7, 7};
    // for(auto& strs : Solution().subsets("25525511135")) cout << strs << endl;

    for(auto& strs : Solution().findSubsequences(nums)) {
        for(auto& str : strs) cout << str;
        cout << endl;
    }
}