#include <vector>
#include <iostream>
#include <list>

using namespace std;

class Solution {
public:
    vector<string> letterMap = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };

    void comb(auto it, int count, string& path, list<string>& paths) {
        // 终止条件: count == 0 (空节点入栈)
        if(!count) paths.push_back(path);
        else {
            // 选择当前字母
            for(char c : letterMap[*it-'0']) {
                
                // 递归
                path.push_back(c);
                comb(it + 1, count-1, path, paths);
                
                // 回溯
                path.pop_back();
                
            }
            
        }
    }

    vector<string> letterCombinations(string digits) {
        list<string> result;
        string path;

        if(digits.size()) comb(digits.begin(), digits.size(), path, result);

        return vector<string>(result.begin(), result.end());
    }
};

int main() {

    for(auto& nums : Solution().letterCombinations("23")) {
        for(auto& num : nums) cout << num;
        cout << endl;
    }

}