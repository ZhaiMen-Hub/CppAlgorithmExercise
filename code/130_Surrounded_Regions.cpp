#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// bfs
class Solution {
public:
    int dirs[4][2] = {0, 1, -1, 0, 0, -1, 1, 0}; // 右上左下 四个方向

    void bfs(int& i, int& j, int& n, int& m, const vector<vector<char>>& board, vector<vector<bool>>& marked) {

        queue<pair<int, int>> q;
        // 加入队列就已经标记
        q.push({i,j});
        marked[i][j] = true;
        
        // 空节点不入栈
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            for(const auto& dir : dirs) {
                // 不越界/不是X且未被标记
                int iNew = p.first + dir[0], jNew = p.second + dir[1];
                if(iNew < 0 || iNew >= n || jNew < 0 || jNew >= m) continue ;
                else if(board[iNew][jNew] == 'X' || marked[iNew][jNew]) continue;
                else {
                    q.push({iNew, jNew});
                    marked[iNew][jNew] = true;
                }
            }
        }

        
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();
        
        // 标记和边界相连的半岛
        // true = 不用修改
        vector<vector<bool>> marked(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // 边界未标记的O
                if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O' && !marked[i][j]) {
                    bfs(i, j, n, m, board, marked);
                }
            }
        }

        // 修改O
        int num = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(!marked[i][j] && board[i][j] == 'O') board[i][j] = 'X';

    }
};

int main() {

    vector<vector<char>> board =  {
                                {'X', 'X', 'X', 'X'},
                                {'X', 'O', 'O', 'X'},
                                {'X', 'X', 'O', 'X'},
                                {'X', 'O', 'X', 'X'}
                                };
    Solution().solve(board);
    for(auto row : board) {
        for(auto node : row) cout << node;
        cout << endl;
    }
    
}