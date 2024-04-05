#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// bfs
class Solution {
public:
    int dirs[4][2] = {0, 1, -1, 0, 0, -1, 1, 0}; // 右上左下 四个方向

    int bfs(const int& i, const int& j, const int& n, const int& m, const vector<vector<int>>& grid, vector<vector<bool>>& visited) {

        queue<pair<int, int>> q;
        // 加入队列就是visited
        visited[i][j] = true;
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
                else if(grid[iNew][jNew] == 0 || visited[iNew][jNew] == true) continue;
                else {
                    visited[iNew][jNew] = true;
                    q.push({iNew, jNew});
                }
            }
        }

        return count;
        
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxArea = 0;

        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && visited[i][j] == false) {
                    // 更新岛屿最大面积
                    maxArea = max(maxArea, bfs(i, j, n, m, grid, visited));
                }
            }
        }

        return maxArea;    
    }
};

int main() {
    vector<vector<int>> grid = {
                                {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
                                };
    cout << Solution().maxAreaOfIsland(grid) << endl;
    
}