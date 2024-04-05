#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // 返回节点的根节点(并缩并路径)
    int find(const int cur, vector<int>& fathers) {
        return fathers[cur] == cur ? cur : fathers[cur] = find(fathers[cur], fathers);
    }
    // 将新的路径加入并查集
    void join(int nodeA, int nodeB, vector<int>& fathers) {
        int fA = find(nodeA, fathers), fB = find(nodeB, fathers);
        if(fA != fB) fathers[fA] = fB; // 如果根节点不同则合并为父子
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        // 构建父集并初始化
        vector<int> fathers(n, 0);
        for(int i = 0; i < n; i++) fathers[i] = i;

        // 构建并查集
        for(const auto& edge : edges) join(edge[0], edge[1], fathers);

        if(find(source, fathers) == find(destination, fathers)) return true;
        else return false;
    }
};

int main() {
    // vector<vector<int>> edges = {
    //                             {0, 1},
    //                             {0, 2},
    //                             {3, 5},
    //                             {5, 4},
    //                             {4, 3}
    //                             };
        vector<vector<int>> edges = {
                                {0, 1},
                                {1, 2},
                                {2, 0},
                                };
    cout << Solution().validPath(6, edges, 0, 2);
}