#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    void reverse(string& s,const int& st,const int& len) {
        // init
        int l = st, r = st + len - 1;
        while(l<r){
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
    
    void removeEmpty(string& s){
        int j = 0;

        for(int i = 0; i < s.size(); i++) {
            // 不是空格，或者是可以保留的空格（不在第一个单词前，且紧贴在单词前）
            if(s[i] != ' ' || j > 0 && i < s.size() - 1 && s[i+1] != ' ') {
                s[j] = s[i];
                j++;
            }
        }

        s.resize(j);
    }

    string& reverseWords(string& s) {
        // 移除多余空格
        removeEmpty(s);
        // 反转整串
        reverse(s,0,s.size());
        // 反转单词，区间为[l,r]，检测到r+1为空格或size()即反转
        int l = 0;
        for(int r = 0; r < s.size(); r++) {
            if(s[r+1] == ' ') {
                reverse(s, l, r-l+1);
                l=r+2;
            }
            // 反转最后一个单词（没有空格）
            else if(r == s.size() - 1) {
                reverse(s, l, r-l+1);
            }
        }

        return s;

    }
};

// 测试
int main() {
    
    string str = "  hello world  ";
    // int k = 2;
    cout << Solution().reverseWords(str) << endl;

}