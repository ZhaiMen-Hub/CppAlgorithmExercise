#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int numRooms = rooms.size();
        vector<bool> isVisited(numRooms, false);
        
        // BFS: 每个节点可以访问的房间，入队则visited
        queue<int> q;
        q.push(0);
        isVisited[0] = true;

        while(!q.empty()) {
            int curRoom = q.front();
            q.pop();
            for(int roomNext : rooms[curRoom]) {
                if(!isVisited[roomNext]) {
                    q.push(roomNext);
                    isVisited[roomNext] = true;
                }
            }
        }

        // 全部访问完则true，否则false
        for(bool b : isVisited) if(!b) return false;
        return true;
    }
};

int main() {
    // vector<vector<int>> rooms = {
    //                             {1, 3},
    //                             {3, 0, 1},
    //                             {2},
    //                             {0}
    //                             };
    vector<vector<int>> rooms = {
                                {1},
                                {2},
                                {3},
                                {}
                                };
    cout << Solution().canVisitAllRooms(rooms) << endl;
}