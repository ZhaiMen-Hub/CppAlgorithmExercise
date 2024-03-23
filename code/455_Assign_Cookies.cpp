#include<vector>
#include<algorithm>
#include<iostream>


using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int result = 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // 遍历胃口，如果能用最大的饼干满足，就分发饼干，否则发给下一个胃口
        for(auto itG = g.rbegin(), itS = s.rbegin(); itG != g.rend() && itS != s.rend(); itG++) {
            if(*(s.rbegin() + result) >= *itG) {
                result++;
                itS++;
            }
        }
        return result;
    }
};

int main() {
    vector<int> g = {1, 2, 3};
    vector<int> s = {3};
    cout << Solution().findContentChildren(g ,s) << endl;

}