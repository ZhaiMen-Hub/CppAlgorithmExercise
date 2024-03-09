#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void getNext(int* next, const string& needle) {
    
        // 前缀指针j(指向前缀倒数第二位)
        int j = 0;
        next[0] = j;
        for(int i = 1; i < needle.size(); i++) {

            // 隐含初始条件：j = next[i-1] 
            
            // 如果不能匹配，回退到能匹配的最短前缀，最多回退到 j=0
            while(j > 0 && needle[i] != needle[j]) {
                j = next[j-1];
            }
            // 如果能找到匹配的前缀，则在此基础上+1，即next[i] = j+1
            if(needle[i] == needle[j]) {
                j++;
            }
            // 找不到，则next[i] = j = 0

            next[i] = j;
        }

    }
    
    bool repeatedSubstringPattern(string s) {

        // 剪枝
        if(s.size() == 0)
            return false;

        // 创建next数组
        int next[s.size()];
        getNext(next, s);

        // 确认最后一位满足关系
        int& next_last = next[s.size()];
        // 排除 next_last = 0 的情况
        if(next_last > 0 && s.size() % (s.size() - next_last) == 0) {
            return true;
        }
        else {
            return false;
        }
        

    }
    
};

// 测试
int main() {
    
    string str = "ababab";
    // int k = 2;
    cout << Solution().repeatedSubstringPattern(str) << endl;

}