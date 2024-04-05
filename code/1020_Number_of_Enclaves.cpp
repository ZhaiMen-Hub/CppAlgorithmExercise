#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// bfs
class Solution {
public:
    int dirs[4][2] = {0, 1, -1, 0, 0, -1, 1, 0}; // 右上左下 四个方向

    void bfs(const int& i, const int& j, const int& n, const int& m, vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        // 加入队列就已经去除
        q.push({i,j});
        grid[i][j] = 0;
        
        // 空节点不入栈
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            for(const auto& dir : dirs) {
                // 不越界/不是海洋
                int iNew = p.first + dir[0], jNew = p.second + dir[1];
                if(iNew < 0 || iNew >= n || jNew < 0 || jNew >= m) continue ;
                else if(grid[iNew][jNew] == 0) continue;
                else {
                    q.push({iNew, jNew});
                    grid[iNew][jNew] = 0;
                }
            }
        }

        
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        
        // 去除和边界相连的半岛
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // 边界未去除的陆地
                if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 1 ) {
                    bfs(i, j, n, m, grid);
                }
            }
        }

        // 计算岛屿数量
        int num = 0;
        for(const auto& row : grid) for(const auto& node : row) num += node;

        return num;    
    }
};

int main() {
    // vector<vector<int>> grid =  {
    //                             {0, 0, 0, 0},
    //                             {1, 0, 1, 0},
    //                             {0, 1, 1, 0},
    //                             {0, 0, 0, 0}
    //                             };
    vector<vector<int>> grid =  {
                                {0, 1, 1, 0},
                                {0, 0, 1, 0},
                                {0, 0, 1, 0},
                                {0, 0, 0, 0}
                                };
    cout << Solution().numEnclaves(grid) << endl;
    
}