#include<vector>
#include<unordered_set>
#include<iostream>

using namespace std;

class Solution {
public:
    bool valid(const int i, const int row, const int col, const vector<vector<char>>& board) {
        // 遍历行/列/小方格
        const int size = 9;
        const int subsize = 3;
        const int subRow = row / subsize;
        const int subCol = col / subsize;
        const char iChar = i + '0';
        for(int j = 0; j < size; j++) {
            // 行/列/小方格
            if(iChar == board[row][j] || iChar == board[j][col] || iChar == board[subRow * subsize + j / subsize][subCol * subsize + j % subsize])
                return false;
        }
        // 均不重复
        return true;
    }
    // 找到就终止
    bool backtrack(const int index, vector<vector<char>>& board) {
        
        const int size = 9;
        // 终止条件：填满数独
        if(index == size * size) return true; // index = row*9+col 属于 [0,80]
        // 递归：如果index要填，在index填数，然后到index+1
        else {
            int row = index / size;
            int col = index % size;
            // 不需要填，填index+1
            if(board[row][col] != '.' ) return backtrack(index + 1, board);
            // 需要填，填完再填index+1
            else {
                for (int i = 1; i <= size; i++) {
                    if(valid(i, row, col, board)) {

                        board[row][col] = i + '0';
                        
                        // 填完就结束，没填完就回溯继续
                        if(backtrack(index + 1, board)) return true;

                        board[row][col] = '.';
                    }
                }
                // 找不到可填的数
                return false;
            }

        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(0, board);
    }
};

int main() {
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution().solveSudoku(board);

    for(auto& strs : board) {
        for(auto& str : strs) cout << str;
        cout << endl;
    }
}