#include <vector>
#include <iostream>

using namespace std;

// // 倒序
// class Solution {
// public:
//     int count = 0;
//     void comb(int ed, int& sum, const int& k, const int& n, vector<int>& path, vector<vector<int>>& paths) {

//         count++;

//         // 倒序
//         // 剪枝条件：求和溢出
//         if(sum > n) return;
//         // 终止条件：长度相等
//         else if(path.size() == k) {
//             if(sum == n) paths.push_back(path);
//             else return;
//         }
//         // 递归条件：放入一个数，然后继续选
//         else {
//             for(int edNew = ed; edNew >= k - path.size(); edNew--) {
//                 path.push_back(edNew);
//                 sum += edNew;
//                 comb(edNew - 1, sum, k, n, path, paths);
//                 path.pop_back();
//                 sum -= edNew;
//             }
//         }
       
        
//     }
    
//     vector<vector<int>> combinationSum3(int k, int n) {

//         vector<vector<int>> paths;
//         vector<int> path;
//         int sum = 0;

//         comb(9, sum, k, n, path, paths);

//         return paths;

//     }
// };


class Solution {
public:
    int count = 0;
    void comb(int st, int& sum, const int& k, const int& n, vector<int>& path, vector<vector<int>>& paths) {

        count++;

        // 正序
        // 不会溢出
        // 终止条件：长度相等
        if(path.size() == k) {
            if(sum == n) paths.push_back(path);
            else return;
        }
        // 递归条件：放入一个数，然后继续选
        // 从小到大，如果加入的数超过n了，跳过当前及后面的循环
        else {
            for(int stNew = st; 9 - stNew + 1 >= k - path.size() && sum + stNew <= n; stNew++) {
                path.push_back(stNew);
                sum += stNew;
                comb(stNew + 1, sum, k, n, path, paths);
                path.pop_back();
                sum -= stNew;
            }
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> paths;
        vector<int> path;
        int sum = 0;

        comb(1, sum, k, n, path, paths);

        return paths;

    }
};

// TODO: 对比双指针

int main() {

    Solution s;
    for(auto& nums : s.combinationSum3(3, 9)) {
        for(auto& num : nums) cout << num;
        cout << endl;
    }
    cout << s.count << endl;

}