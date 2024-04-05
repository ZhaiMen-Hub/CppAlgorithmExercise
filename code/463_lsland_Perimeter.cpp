#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// bfs
class Solution {
public:
    int dirs[4][2] = {0, 1, -1, 0, 0, -1, 1, 0}; // 右上左下 四个方向

    int dfs(const int& i, const int& j, const int& n, const int& m, const vector<vector<int>>& grid, vector<vector<bool>>& isVistedMat) {

        // 终止条件: 搜完四个边
        int border = 0;
        // 处理当前节点
        isVistedMat[i][j] = true;

        for(const auto& dir : dirs) {
            int iNew = i + dir[0], jNew = j + dir[1];
            // 空节点不递归
            // 递归停止条件: 越界 / 海洋 (+1) 或 已访问 
            if(iNew < 0 || iNew >= n || jNew < 0 || jNew >= m || grid[iNew][jNew] == 0) {
                border++;
                continue;
            }
            else if(isVistedMat[i][j]) continue;
            else{
                border += dfs(iNew, jNew, n, m, grid, isVistedMat);
            }
        }

        return border; 
        
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> isVistedMat(n , vector<bool>(m, false));
        
        // 计算边界
        int border = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // 未访问的陆地（不能沉掉岛屿，会影响边界计算
                if(grid[i][j] == 1 && !isVistedMat[i][j]) {
                    border += dfs(i, j, n, m, grid, isVistedMat);
                }
            }
        }


        return border;    
    }
};

int main() {

    vector<vector<int>> grid =  {
                                {0, 1, 0, 0},
                                {1, 1, 1, 0},
                                {0, 1, 0, 0},
                                {1, 1, 0, 0}
                                };
    cout << Solution().islandPerimeter(grid) << endl;
    
}