#include<iostream>
#include<vector>

using namespace std;

int main() {
    int M = 6,N = 1;
    // cin >> M >> N;
    // cout << M << N << endl;
    // vector<int> mVec(M), nVec(M);
    // for(auto& m : mVec) cin >> m;
    // for(auto& n : nVec) cin >> n;
    vector<int> mVec = {2, 2, 3, 1, 5, 2}, nVec = {2, 3, 1, 5, 4, 3};

    // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i])
    vector<int> dp(N + 1, 0); // dp[0][0, N];

    // 给定物品，遍历重量
    // 从dp[0]到dp[M-1]
    for(int i = 0; i < M; i++) {
        // 更新所有重量下的最优选择：是否把物品i放进
        for(int j = N; j >= 0; j--) {
            if(j >= mVec[i]) dp[j] = max(dp[j], dp[j - mVec[i]] + nVec[i]);
        }
    }

    cout << dp[N] << endl;

}