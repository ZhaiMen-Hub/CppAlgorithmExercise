#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    s = "a1b2c3";
    // cin >> s;

    // 统计数字个数
    int count = 0;
    for(const auto& c : s) {
        if('0' <= c && c <= '9') {
            count++;
        }
    }

    // cout << count << endl;

    // 扩充字符串
    int len_org = s.size();
    s.resize(s.size() + count*5);

    // 双指针逆序填充
    int it_dst = s.size() - 1;
    for(int it_org = len_org - 1; it_org >= 0; it_org--) {

        // 剪枝
        if(it_org == it_dst) {
            break;
        }
        else {
            if('0' <= s[it_org] && s[it_org] <= '9') {
            // 取 s [it_dst-5, it_dst] 的切片
            
            s.replace(it_dst-5, 6, "number");
            it_dst -= 6;
            }
            else {
                s[it_dst] = s[it_org];
                it_dst--;
            }
        }
    }

    // 输出
    cout << s;


}