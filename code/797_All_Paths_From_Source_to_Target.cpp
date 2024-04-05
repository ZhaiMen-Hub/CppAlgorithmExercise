#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    void dfs(const int& src, const int& dst, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& paths) {
        
        // 终止条件：已经到达
        if(src == dst) paths.push_back(path);
        // 递归条件：从src节点走到下一个可以走的节点
        else {
            for(const int& next : graph[src]) {
                // 加入
                path.push_back(next);
                // 递归
                dfs(next, dst, graph, path, paths);
                // 回溯
                path.pop_back();
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path{0};

        dfs(0, graph.size() - 1, graph, path, paths);

        return paths;
    }
};

int main(){

}