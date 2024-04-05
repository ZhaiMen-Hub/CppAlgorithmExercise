#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

// bfs
class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 建立哈希表
        unordered_set<string> s(wordList.begin(), wordList.end());
        unordered_map<string, int> m; // 字符串/变换次数 (已入队)

        // 剪枝
        if(s.find(endWord) == s.end()) return 0;

        // DFS
        queue<string> q;
        q.push(beginWord);
        m[beginWord] = 1;

        // 取值范围: 字符数 x 26
        while(!q.empty()) {
            string curWord = q.front();
            q.pop();
            for(int i = 0; i < curWord.size(); i++) {
                for(char c : "abcdefghijklmnopqrstuvwxyz") {
                    // 表里有且未入栈
                    string newWord(curWord);
                    newWord[i] = c;
                    if(s.find(newWord) != s.end() && !m[newWord]) {
                        m[newWord] = m[curWord] + 1;
                        q.push(newWord);
                    }
                    // 找到则结束
                    if(newWord == endWord) return m[newWord];
                }
            }
        }
        // 找不到路径
        return 0;
    }
};

int main() {

    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << Solution().ladderLength("hit", "cog",wordList) << endl;
    
}