#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

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
                
                // 除了第一个(下标不越界)，使用的元素不能和前一次相同（相同的元素只用一次）
                if(i == 0 || *(stIt + i) != *(stIt + (i - 1))) {
                    path.push_back(*(stIt + i));

                    backtrack(stIt + (i + 1), count - (i + 1), path, paths);

                    path.pop_back();
                }
            }
        }
        
    }

    vector<vector<int>> subsetsWithDup(vector<int> nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> paths;
        vector<int> path;

        backtrack(nums.begin(), nums.size(), path, paths);

        return paths;
    }
};

int main() {
    vector<int> nums = {1, 2, 2};
    // for(auto& strs : Solution().subsets("25525511135")) cout << strs << endl;

    for(auto& strs : Solution().subsetsWithDup(nums)) {
        for(auto& str : strs) cout << str;
        cout << endl;
    }
}