#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindorme(const string::iterator stIt, const int& count) {
        for(int l = 0, r = count - 1; l < r; l++, r--) {
            if(*(stIt + l) != *(stIt + r)) return false;
        }
        return true;
    }
    void part(const string::iterator stIt, const int& count, vector<string>& path, vector<vector<string>>& paths) {
        
        // 终止条件
        if(count == 0) paths.push_back(path);
        // 递归条件: 切割长度为i = [1, count]的字符串，余下的递归继续切
        // 非回文串不入栈
        for(int i = 1; i <= count; i++) {

            if(isPalindorme(stIt, i)) {
                
                // 取值
                path.push_back(string(stIt, stIt + i));

                // 递归
                part(stIt + i, count - i, path, paths);

                // 回溯
                path.pop_back();
            }

        }
    }
    vector<vector<string>> partition(string s) {

        vector<vector<string>> paths;
        vector<string> path;

        part(s.begin(), s.size(), path, paths);

        return paths;

    }
};

int main() {
    for(auto& strs : Solution().partition("aab")) {
        for(auto& str : strs) cout << str << endl;
        cout << endl;
    }
}