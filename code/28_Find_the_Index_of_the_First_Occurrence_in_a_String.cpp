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
    int strStr(const string& haystack, const string& needle) {

        if (needle.size() == 0) {
            return 0;
        }

        int next[needle.size()];
        getNext(next, needle);

        // for(int i = 0; i < needle.size(); i++) cout << next[i] ;
        // cout << endl;

        // 前缀指针
        int j = 0;
        for(int i = 0; i < haystack.size(); i++) {
            // 如果不能匹配，回退到能匹配的最短前缀，最多回退到 j=0
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j-1];
            }
            // 如果能找到匹配的前缀，则在此基础上+1，即next[i] = j+1
            if(haystack[i] == needle[j]) {
                j++;
            }
            // 如果前缀长度等于整个字符串(j = needle.size())，匹配完成
            // 注意j指向未匹配的位置，应该在整个字符串后（
            if (j == needle.size()) {
                return i-j+1;
            }
        }

        // 匹配失败
        return -1;

    }
};

// // 前缀表从0开始
// class Solution {
// public:
//     void getNext(int* next, const string& s) {
//         int j = 0;
//         next[0] = 0;
//         for(int i = 1; i < s.size(); i++) {
//             // j = next[i-1]
//             while (j > 0 && s[i] != s[j]) {
//                 j = next[j - 1];
//             }
//             if (s[i] == s[j]) {
//                 j++;
//             }
//             next[i] = j;
//         }
//     }
//     int strStr(string haystack, string needle) {
//         if (needle.size() == 0) {
//             return 0;
//         }
//         int next[needle.size()];
//         getNext(next, needle);

//         for(int i = 0; i < needle.size(); i++) cout << next[i] ;
//         cout << endl;
        
//         int j = 0;
//         for (int i = 0; i < haystack.size(); i++) {
//             while(j > 0 && haystack[i] != needle[j]) {
//                 j = next[j - 1];
//             }
//             if (haystack[i] == needle[j]) {
//                 j++;
//             }
//             if (j == needle.size() ) {
//                 return (i - needle.size() + 1);
//             }
//         }
//         return -1;
//     }
// };

// 测试
int main() {
    
    string haystack = "aabaabaafa";
    string needle = "aabaaf";
    
    cout << Solution().strStr(haystack, needle) << endl;

}