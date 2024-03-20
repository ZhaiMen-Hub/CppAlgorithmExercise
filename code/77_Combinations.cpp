#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // 递归组合
    // 倒序比较方便，少传一个参数
    void comb(int n, int k, vector<int>& path, vector<vector<int>>& result) {
        // 终止条件: k = 0 （空节点入栈）
        if(k==0) result.push_back(path);
        // 递归条件：Cnk = Cn1 * C(n-1)(k-1)
        // 从[1,n]选一个n_new, 然后从[1,n_new-1]选k-1个，显然n_new>=k
        else {
            for(int n_new = n; n_new >= k; n_new--) {

                // 递归到下一层
                path.push_back(n_new);
                comb(n_new-1, k-1, path, result);

                // 回溯到上一层
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        // 创建结果变量
        vector<vector<int>> result;
        vector<int> path;

        comb(n, k, path, result);

        // 返回
        return result;
    }
};

int main() {

    for(auto& nums : Solution().combine(4, 2)) {
        for(auto& num : nums) cout << num;
        cout << endl;
    }

}