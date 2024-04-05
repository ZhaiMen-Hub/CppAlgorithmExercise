#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

// bfs
class Solution {
public:
    int dirs[4][2] = {0, 1, -1, 0, 0, -1, 1, 0}; // 右上左下 四个方向

    int bfs(const int& i, const int& j, const int& n, const int& m, const vector<vector<int>>& grid, vector<vector<int>>& island, const int& index) {

        queue<pair<int, int>> q;
        // 加入队列就是visited
        island[i][j] = index;
        q.push({i,j});
        int count = 0;
        
        // 空节点不入栈
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            // 处理时才计数，push时不计数
            count++;
            for(const auto& dir : dirs) {
                // 不越界/不是海洋/未访问过
                int iNew = p.first + dir[0], jNew = p.second + dir[1];
                if(iNew < 0 || iNew >= n || jNew < 0 || jNew >= m) continue ;
                else if(grid[iNew][jNew] == 0 || island[iNew][jNew] != 0) continue;
                else {
                    island[iNew][jNew] = index;
                    q.push({iNew, jNew});
                }
            }
        }

        return count;
        
    }

    int largestIsland(vector<vector<int>>& grid) {


        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> island(n, vector<int>(m, 0));   //  哈希表: 坐标 - 岛屿编号
        unordered_map<int, int> mapIsland; // 哈希表: 岛屿编号 - 面积
        mapIsland[0] = 0; // 海洋兼容初始化为0
        int index = 0; // 岛屿编号(先++再使用)
        
        // 标定岛屿
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && island[i][j] == 0) {
                    // 标定新岛屿坐标和记录面积
                    index++;
                    mapIsland[index] = bfs(i, j, n, m, grid, island, index);
                }
            }
        }

        // 遍历可以填的地方
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // 如果是海洋，尝试造岛
                if(grid[i][j] == 0) {
                    // 人工岛面积为相邻岛(合法)面积之和+1 (海洋兼容初始化为0)
                    int curArea = 1;
                    // 防止岛屿重复记录
                    unordered_set<int> setIsland;
                    for(const auto& dir : dirs) {
                        int iNew = i + dir[0], jNew = j + dir[1];
                        if(iNew >= 0 && iNew < n && jNew >= 0 && jNew < m) {
                            int curIsland = island[iNew][jNew];
                            if(setIsland.find(curIsland) == setIsland.end()) {
                                setIsland.insert(curIsland);
                                curArea += mapIsland[curIsland];
                            }
                        }
                    }
                    if(curArea > maxArea) maxArea = curArea;
                }
            }
        }

        if(maxArea == 0) return n*m; // 没有空位则已经填满
        else return maxArea;
    }
};

int main() {
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    cout << Solution().largestIsland(grid) << endl;
    
}