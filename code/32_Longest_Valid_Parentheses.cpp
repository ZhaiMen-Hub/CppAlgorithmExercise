#include <stack>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        
        // 下标栈
        stack<int> st;

        // 有效数组
        vector<bool> valid(s.size(), false);

        // 模拟
        for(int i = 0; i < s.size(); i++) {
            // 匹配则弹出并置位
            if(!st.empty()) {
                auto& cur = st.top();
                if(s[cur] == '(' && s[i] == ')') {
                    valid[cur] = true;
                    valid[i] = true;
                    st.pop();
                }
                else st.push(i);
            }
            // 不匹配则塞入
            else st.push(i);
        }

        // 计数
        int maxLen = 0;
        int curLen = 0;
        for(bool b : valid) {
            if(b == true) {
                curLen++;
                if(curLen > maxLen) maxLen = curLen;
            }
            else curLen = 0;
        }
        return maxLen;

    }
};


int main() {
    cout << Solution().longestValidParentheses(")()())") << endl;
}