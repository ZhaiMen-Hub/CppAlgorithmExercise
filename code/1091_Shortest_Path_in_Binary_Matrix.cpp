#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        if (grid[0][0] == 1) return -1;

        vector<vector<int>> dirs = {{-1,0}, {-1,-1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

        // {dist, rowIndex, colIndex}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> open;
        open.push({1, 0, 0});
        vector<vector<bool>> closed(n, vector<bool>(n, false));
        vector<vector<vector<int>>> parent(n, vector<vector<int>>(n, {-1, -1})); // {rowIndex, colIndex} -> parent {rowIndex, colIndex}
        vector<vector<int>> minDist(n, vector<int>(n, INT_MAX));
        minDist[0][0] = 1;

        while(!open.empty()){

            // pop
            int curRowIndex = open.top()[1], curColIndex = open.top()[2];
            open.pop();
            closed[curRowIndex][curColIndex] = true;

            if(curRowIndex == n - 1 && curColIndex == n - 1) {
                while(curRowIndex != -1 && curColIndex != -1){
                    cout << curRowIndex << curColIndex << endl;
                    int prevRowIndex = parent[curRowIndex][curColIndex][0];
                    int prevColIndex = parent[curRowIndex][curColIndex][1];
                    curRowIndex = prevRowIndex;
                    curColIndex = prevColIndex;
                }
                return minDist[n - 1][n - 1];
            }

            // add / update Neighbor
            for(const auto& dir: dirs){
                int nextRowIndex = curRowIndex + dir[0], nextColIndex = curColIndex + dir[1];
                // 合法 / 非障碍 / 未访问 / 更新
                if(nextRowIndex >= 0 && nextRowIndex < n && nextColIndex >= 0 && nextColIndex < n && grid[nextRowIndex][nextColIndex] == 0 && !closed[nextRowIndex][nextColIndex]){
                    if(minDist[curRowIndex][curColIndex] + 1 < minDist[nextRowIndex][nextColIndex]){
                        minDist[nextRowIndex][nextColIndex] = minDist[curRowIndex][curColIndex] + 1; // update
                        // Dijstra update
                        // open.push({minDist[nextRowIndex][nextColIndex], nextRowIndex, nextColIndex}); 
                        // A star update
                        open.push({minDist[nextRowIndex][nextColIndex] + min(abs(n - 1 - nextRowIndex), abs(n - 1 - nextColIndex)), nextRowIndex, nextColIndex});
                        parent[nextRowIndex][nextColIndex] = {curRowIndex, curColIndex}; // update
                    }
                }
            }     
        }

        // no solution
        return -1;
    }
};
