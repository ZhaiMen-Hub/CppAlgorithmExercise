#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {

        int l = 0;
        int r = s.size() - 1;
        while(l < r) {
            swap(s[l], s[r]);

            // update iterator
            l++;
            r--;
        }
    }
};

// 测试
int main() {
    vector<char> str = {'a','b','c'};

    Solution().reverseString(str);

    for(const auto& c : str) cout << c;
    cout << endl;

}