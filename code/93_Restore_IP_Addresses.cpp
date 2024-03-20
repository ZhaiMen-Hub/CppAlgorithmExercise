#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isIpAddresses(const string::iterator stIt, const int count) {
        
        // 不传入空字符串
        // 长度>1时起始!=0
        if (count > 1 && *stIt == '0') return false;
        // 满足范围
        else {
            int ip = stoi(string(stIt, stIt + count));
            if(ip > 255) return false;
            else return true;
        }

    }
    void part(string::iterator stIt, int count, int section, vector<string>& path, vector<string>& paths) {

        // 终止条件：最后一个section
        if(section == 1) {
            if(isIpAddresses(stIt, count)) {
                // 前三段 + 最后一段
                paths.push_back(path[0] + '.' + path[1] + '.' + path[2] + '.' + string(stIt, stIt + count));
            }
        }
        // 递归条件：继续切分
        // 剪枝：剩余长度在[(section-1)*1, (section-1)*3]之间
        // 根据终止条件，section>1，一定有剩余
        else {
            for(int i = 1; i <= 3 ; i++) {
                    
                // 不能切太长太短
                if(count - i >= section - 1 && count - i <= 3 * (section - 1)) {
                    if(isIpAddresses(stIt, i)) {
                        // 切分
                        path.push_back(string(stIt,stIt + i));
                        // 递归
                        part(stIt + i, count - i, section - 1, path, paths);
                        // 回溯
                        path.pop_back();
                    }
                }

            }
        }

    }
    vector<string> restoreIpAddresses(string s) {

        vector<string> paths;
        vector<string> path;

        part(s.begin(), s.size(), 4, path, paths);

        return paths;

    }
};

int main() {
    for(auto& strs : Solution().restoreIpAddresses("25525511135")) cout << strs << endl;

    // for(auto& strs : Solution().restoreIpAddresses("aab")) {
    //     for(auto& str : strs) cout << str << endl;
    //     cout << endl;
    // }
}