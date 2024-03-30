#include<iostream>
#include<vector>

using namespace std;

int main() {
    int N = 4, V = 5;
    cin >> N >> V;
    vector<int> w(N), v(N);
    for(int i = 0; i < N; i++) cin >> w[i] >> v[i];
    
    // w = vector<int>{1};
    // v = vector<int>{2};
    // N = 1;
    // V = 5;
    
    vector<int> dp(V + 1, 0);
    
    // 遍历物品
    for(int i = 0; i < N; i++) {
        // 遍历背包（装得下的情况
        for(int j = w[i]; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    
    cout << dp.back();
    
}