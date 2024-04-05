#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// // dfs
// class Solution {
// public:
//     int dirs[4][2] = {0, 1, -1, 0, 0, -1, 1, 0}; // 右上左下 四个方向

//     void dfs(const int& i, const int& j, const int& n, const int& m, const vector<vector<char>>& grid, vector<vector<bool>>& visited) {

//         // 终止条件：越界/访问过 （不越界才能读取visited）
//         if(i < 0 || i >= n || j < 0 || j >= m) return ;
//         else if(grid[i][j] == '0' || visited[i][j] == true) return;
//         // 递归条件：visit当前节点 & 搜索相邻节点
//         else {
//             visited[i][j] = true;
//             // 空节点入栈
//             for(const auto& dir : dirs) dfs(i + dir[0], j + dir[1], n, m, grid, visited);
//         }
//     }

//     int numIslands(vector<vector<char>>& grid) {

//         int count = 0;

//         int n = grid.size();
//         int m = grid[0].size();
//         // cout << m << n << endl;
//         vector<vector<bool>> visited(n, vector<bool>(m, false));
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 if(grid[i][j] == '1' && visited[i][j] == false) {
//                     count++;
//                     // cout << count << endl;
//                     dfs(i, j, n, m, grid, visited);
//                 }
//             }
//         }

//         return count;    
//     }
// };

// // dfs2
// class Solution {
// public:
//     int dirs[4][2] = {0, 1, -1, 0, 0, -1, 1, 0}; // 右上左下 四个方向

//     void dfs(const int& i, const int& j, const int& n, const int& m, const vector<vector<char>>& grid, vector<vector<bool>>& visited) {

//         // 终止条件：空节点不入栈，循环完即终止
//         visited[i][j] = true;
//         // 空节点不入栈
//         for(const auto& dir : dirs) {
//             // 不越界/不是海洋/未访问过
//             int iNew = i + dir[0], jNew = j + dir[1];
//             if(iNew < 0 || iNew >= n || jNew < 0 || jNew >= m) continue ;
//             else if(grid[iNew][jNew] == '0' || visited[iNew][jNew] == true) continue;
//             else dfs(iNew, jNew, n, m, grid, visited);
//         }
        
//     }

//     int numIslands(vector<vector<char>>& grid) {

//         int count = 0;

//         int n = grid.size();
//         int m = grid[0].size();
        
//         vector<vector<bool>> visited(n, vector<bool>(m, false));
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 if(grid[i][j] == '1' && visited[i][j] == false) {
//                     count++;
//                     dfs(i, j, n, m, grid, visited);
//                 }
//             }
//         }

//         return count;    
//     }
// };

// bfs
class Solution {
public:
    int dirs[4][2] = {0, 1, -1, 0, 0, -1, 1, 0}; // 右上左下 四个方向

    void bfs(const int& i, const int& j, const int& n, const int& m, const vector<vector<char>>& grid, vector<vector<bool>>& visited) {

        queue<pair<int, int>> q;
        // 加入队列就是visited
        visited[i][j] = true;
        q.push({i,j});
        
        // 空节点不入栈
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            // cout << p.first << p.second << endl;
            for(const auto& dir : dirs) {
                // 不越界/不是海洋/未访问过
                int iNew = p.first + dir[0], jNew = p.second + dir[1];
                if(iNew < 0 || iNew >= n || jNew < 0 || jNew >= m) continue ;
                else if(grid[iNew][jNew] == '0' || visited[iNew][jNew] == true) continue;
                else {
                    visited[iNew][jNew] = true;
                    q.push({iNew, jNew});
                }
            }
        }
        
    }

    int numIslands(vector<vector<char>>& grid) {

        int count = 0;

        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && visited[i][j] == false) {
                    count++;
                    bfs(i, j, n, m, grid, visited);
                }
            }
        }

        return count;    
    }
};

int main() {
    vector<vector<char>> grid = {
                                {'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'}
                                };
    cout << Solution().numIslands(grid) << endl;
}