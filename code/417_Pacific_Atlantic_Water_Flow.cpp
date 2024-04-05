#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// bfs
class Solution {
public:
    int dirs[4][2] = {0, 1, -1, 0, 0, -1, 1, 0}; // 右上左下 四个方向

    void bfs(const int& i, const int& j, const int& n, const int& m, const vector<vector<int>>& grid, vector<vector<bool>>& marked) {

        queue<pair<int, int>> q;
        // 加入队列就已经标记
        q.push({i,j});
        marked[i][j] = true;
        
        // 空节点不入栈
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            for(const auto& dir : dirs) {
                // 不越界，高度不低且未标记
                int iNew = p.first + dir[0], jNew = p.second + dir[1];
                if(iNew < 0 || iNew >= n || jNew < 0 || jNew >= m) continue ;
                else if(grid[iNew][jNew] < grid[p.first][p.second] || marked[iNew][jNew]) continue;
                else {
                    q.push({iNew, jNew});
                    marked[iNew][jNew] = true;
                }
            }
        }

        
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, false)), alt(pac);
        // 列
        for(int i = 0; i < n; i++) {
            if(!pac[i][0]) bfs(i, 0, n, m, grid, pac);
            if(!alt[i][m-1]) bfs(i, m-1, n, m, grid, alt);
        }
        // 行
        for(int i = 0; i < m; i++) {
            if(!pac[0][i]) bfs(0, i, n, m, grid, pac);
            if(!alt[n-1][i]) bfs(n-1, i, n, m, grid, alt);
        }

        vector<vector<int>> result;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(pac[i][j] && alt[i][j]) result.push_back({i,j});
        return result;
        
    }
};

int main() {

    vector<vector<int>> grid =  {
                                {1, 2, 2, 3, 5},
                                {3, 2, 3, 4, 4},
                                {2, 4, 5, 3, 1},
                                {6, 7, 1, 4, 5},
                                {5, 1, 1, 2, 4}
                                };

    for(auto p : Solution().pacificAtlantic(grid)) cout << p[0] << p[1] << endl;
    
}