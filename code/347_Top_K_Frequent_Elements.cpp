// #include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
// #include <map>
// #include <utility>

using namespace std;

// class Solution {
// public:

//     // a>b, top最小
//     class cmp {
//     public:
//         bool operator() (const pair<int,int>& left, const pair<int,int>& right) {
//             return left.second > right.second;
//         }   
//     };

//     vector<int> topKFrequent(vector<int>& nums, int k) {

//         // 统计数量
//         unordered_map<int, int> m;
//         for(auto& num : nums) m[num]++;

//         // 优先队列
//         priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> p;
//         for(auto it = m.begin(); it != m.end(); it++) {
//             // 压入
//             p.push(pair<int,int>(*it));
//             // 弹出
//             if(p.size()>k) {
//                 p.pop();
//             }
//         }

//         // 建立结果
//         vector<int> result(k);
//         int i = k - 1;
//         while(!p.empty()) {
//             result[i] = p.top().first;
//             p.pop();
//             i--;
//         }
        
//         return result;

//     }
// };

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // 统计数量
        unordered_map<int, int> m;
        for(auto& num : nums) m[num]++;

        // 优先队列
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;

        // 排序
        for(auto it = m.begin(); it != m.end(); it++) {
            // 压入
            p.push(pair<int,int>{it->second, it->first});
            // 弹出
            if(p.size()>k) {
                p.pop();
            }
        }

        // 建立结果
        vector<int> result(k);
        for(int i = k - 1; i >= 0; i--) {
            result[i] = p.top().second;
            p.pop();
        }
        return result;
    }
};

int main() {
    vector<int>nums = {1,1,1,2,2,3};
    for (auto num : Solution().topKFrequent(nums, 2)) cout << num << endl;
}