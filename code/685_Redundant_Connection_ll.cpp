#include<iostream>
#include<vector>

using namespace std;

class MySet {
public:
    vector<int> fathers;

    // father初始化
    MySet(int numNode): fathers(numNode, 0) {
        for(int i = 0; i < numNode; i++) fathers[i] = i;
    }

    // 返回节点的根节点(并缩并路径)
    int find(const int node) {
        return fathers[node] == node ? node : fathers[node] = find(fathers[node]);
    }

    // 将新的路径加入并查集
    void join(int nodeA, int nodeB) {
        int fA = find(nodeA), fB = find(nodeB);
        if(fA != fB) fathers[fA] = fB; // 如果根节点不同则合并为父子
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        // 建立并初始化并查集
        MySet mySet(1000); // 节点数量上限1k

        for(const auto& edge : edges){
            int f0 = mySet.find(edge[0]);
            int f1 = mySet.find(edge[1]);
            // 重复的，直接返回
            if(f0 == f1) return edge;
            // 不重复，根节点合并为父子
            else mySet.fathers[f0] = f1;
        }

        return {0, 0}; // 用不到，为了编译能过

    }
};


int main() {

    vector<vector<int>> edges = {
                            {1, 2},
                            {1, 3},
                            {2, 3},
                            };

    for(int i : Solution().findRedundantConnection(edges)) cout << i << endl;

}