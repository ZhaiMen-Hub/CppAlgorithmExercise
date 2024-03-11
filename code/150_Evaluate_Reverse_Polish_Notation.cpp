#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        // 建立栈
        stack<long long> st;
        
        for(auto& str: tokens) {

            // 判断是运算符还是数字
            // 运算符则运算，数字则压入栈
            if(str == "+" || str == "-" || str == "*" || str == "/") {
                long long num2 = st.top();
                st.pop();
                // 不pop/push，直接修改top
                if(str == "+") st.top() += num2;
                else if(str == "-") st.top() -= num2;
                else if(str == "*") st.top() *= num2;
                else if(str == "/") st.top() /= num2;
                else ; // illegal calculation
            }
            
            else st.push(stoll(str));

        }

        return st.top();
    }
};

int main() {

    // std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    vector<string> tokens = {"-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"};

    // // 打印生成的 vector<string> 中的每个元素
    // for (const std::string& token : tokens) {
    //     std::cout << token << " ";
    // }
    // std::cout << std::endl;

    cout << Solution().evalRPN(tokens) << endl;
}