#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int fib(int n) {

        // 剪枝 n=0
        if(n == 0) return 0;

        int f[2] = {0, 1}; // F(0) and F(1)
        int swap;

        // 求F(n)需要求和n-1次
        for(int i = 0; i < n - 1; i++) {
            swap = f[1];
            f[1] += f[0];
            f[0] = swap;
        }
        return f[1];
    }
};


int main() {
    cout << Solution().fib(5) << endl;
}