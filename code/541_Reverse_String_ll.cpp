#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {

        // 对[i,i+2k)的区间进行处理
        for(int i = 0; i < s.size(); i += 2 * k)
        {
            // 对[i, i+k/size.end()) 进行反转
            auto st = s.begin() + i;
            auto ed = s.begin() + i + min(k, int(s.size()-i));
            reverse(st, ed);
        }

        // 返回结果
        return s;
    }
};

// 测试
int main() {
    
    string str = "abcdefg";
    int k = 2;
    cout << Solution().reverseStr(str, k) << endl;

}