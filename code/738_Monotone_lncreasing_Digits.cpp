#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

// // 求和法
// class Solution {
// public:
//     int monotoneIncreasingDigits(int n) {
//         int ones = 111111111;
//         int result = 0;
//         // 最后一位最大为9，不能加超过9次
//         for(int i = 0; i < 9; i++) {
//             // 移到能加
//             while(result + ones > n) ones /= 10;
//             // 加到最多(for计数)
//             result += ones;
//         }
//         return result;
//     }
// };

// 修改法
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        int result = 0;
        int flag = num.size();
        // 从后往前遍历，修改非递增间隔
        for(int i = num.size() - 1; i > 0; i--) {
            if(num[i - 1] > num[i]) {
                num[i - 1]--;
                flag = i;
            }
        }
        // 赋值
        for(int i = flag; i < num.size(); i++) num[i] = '9';
        return stoi(num);
    }
};



int main() {
    // vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution().monotoneIncreasingDigits(332) << endl;

}