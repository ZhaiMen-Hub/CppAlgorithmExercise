#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        // 去重
        for (const auto& c : s) {
            // 相同的去掉，不同的留下
            if(!st.empty() && c == st.top())
                st.pop();
            else
                st.push(c);
        }
        // 倒出来到string里，倒序
        string result(st.size(), ' ');
        for(auto it = result.rbegin(); it != result.rend(); it++) {
            *it = st.top();
            st.pop();
        }
        
        // 返回结果
        return result;
    }
};

int main() {

    cout << Solution().removeDuplicates("abbaca") << endl;
}