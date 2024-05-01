#include <iostream>
#include <cmath>

using namespace std;

// // newton method
// class Solution {
// public:
//     int mySqrt(int x) {
//         if(x == 0) return 0;
//         else {
//             double C = x, xLast = x - 1, xCur = x; // 兼容初始化xlast
//             while(fabs(xCur - xLast) > 0.1) {
//                 // update xCur, xLast
//                 double xNew = (xCur + C / xCur) / 2;
//                 xLast = xCur;
//                 xCur = xNew;
//                 // cout << xLast << xCur << endl;
//             }
//             return int(xCur);
//         }

//     }
// };

// 二分法(浮点)
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        else {
            // double C = x, xLast = x - 1, xCur = x; // 兼容初始化xlast
            double left = 0, right = x;
            while(right - left > 0.1) {
                // update left, right
                double mid = left + (right - left) / 2;
                if(mid * mid > x) {
                    // return left segment
                    right = mid;                    
                }
                else {
                    left = mid;
                }
                
                
            }
            // 浮点数运算误差，完全平方数要取round，否则返回-1
            // ceil 可能会溢出int
            long rightInt = round(right);
            if(rightInt * rightInt <= x) return rightInt;
            else return rightInt - 1;
        }

    }
};

// 二分法 int
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        else {
            int left = 0, right = x;
            while(right - left > 1) {
                // update left, right
                int mid = left + (right - left) / 2;
                cout << mid << endl;
                if(long(mid) * mid > x) {
                    // return left segment
                    right = mid;                    
                }
                else {
                    left = mid;
                }
                
                
            }
            
            if(long(right) * right == x) return right;
            else return left;
        }

    }
};

int main() {
    cout << Solution().mySqrt(102) << endl;
}