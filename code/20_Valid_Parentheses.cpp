#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            switch(c) {

                // 左括号：添加对应的右括号
                case '(':
                    st.push(')');
                    break;
                case '[':
                    st.push(']');
                    break;
                case '{':
                    st.push('}');
                    break;

                // 右括号：匹配相应的右括号
                // 匹配不上 or 左括号太少/太多 则返回 false
                default:
                    if(st.empty())
                        return false;
                    else
                        if(c != st.top())
                            return false;
                        else
                            st.pop();
            }
        }
        if(st.empty())
            return true;
        // 左括号太多
        else
            return false;
    }
};

int main() {

    cout << Solution().isValid("[{()}]") << endl;
}