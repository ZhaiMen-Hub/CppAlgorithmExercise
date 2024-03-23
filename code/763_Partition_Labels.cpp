#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        // 字母最后下标集合
        int m['z' - 'a' + 1] = {0};

        // 记录最后下标
        for(int i = 0; i < s.size(); i++) m[s[i] - 'a'] = i;

        // 切分字符串
        int rightBound = 0; // 兼容初始化
        int beginIt = -1; // 兼容初始化
        vector<int> result;
        for(int i = 0; i < s.size(); i++) {

            // 先更新后检测
            if(m[s[i] - 'a'] > rightBound) rightBound = m[s[i] - 'a'];
            // 检测
            if(i == rightBound) {
                result.push_back(i - beginIt); // 区间为 (begin_It, i]
                beginIt = i;
            }

        }

        return result;
    }
};


int main() {
    for(auto num : Solution().partitionLabels("ababcbacadefegdehijhklij")) cout << num << endl;
    // cout << Solution().partitionLabels("ababcbacadefegdehijhklij") << endl;

}