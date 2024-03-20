#include<vector>
#include<unordered_set>
#include<iostream>

using namespace std;

class Solution {
public:
    // 终止条件：占用set
    unordered_set<int> col;
    unordered_set<int> diag1;
    unordered_set<int> diag2;
    
    bool validQueen(int i, int j) {
        // 列和两对角线都未占用，可以放
        if(col.find(j) == col.end() && diag1.find(i-j) == diag1.end() && diag2.find(i+j) == diag2.end()) return true;
        else return false;
    }
    
    void backtrack(int rowIndex, int n, vector<string>& board, vector<vector<string>>& boards) {
        // 终止条件：放完n个棋
        if(rowIndex == n) boards.push_back(board);
        // 递归条件：继续在rotIndex放棋
        else {
            // 如果可以下，递归回溯
            for(int j = 0; j < n; j++) {

                if(validQueen(rowIndex, j)) {

                    // 放棋&置位
                    board[rowIndex][j] = 'Q';
                    col.insert(j);
                    diag1.insert(rowIndex - j);
                    diag2.insert(rowIndex + j);

                    backtrack(rowIndex + 1, n, board, boards);

                    // 回溯
                    board[rowIndex][j] = '.';
                    col.erase(j);
                    diag1.erase(rowIndex - j);
                    diag2.erase(rowIndex + j);

                }
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        // 嵌套初始化棋盘
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> boards;

        // 递归放子
        backtrack(0, n, board, boards);

        return boards;

    }
};

int main() {
    for(auto& strs : Solution().solveNQueens(4)) {
        for(auto& str : strs) cout << str;
        cout << endl;
    }
}