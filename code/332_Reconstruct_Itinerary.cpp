#include<vector>
#include<unordered_set>
#include<iostream>
#include<unordered_map>
#include<map>

using namespace std;

class Solution {
public:
    bool backtrack(const string st, int& numTicket, map<string, map<string,int>>& ticketMap, vector<string>& path) {
        // 终止条件：用完所有机票
        if(!numTicket) {
            // 加入最后一个机场
            path.push_back(st);
            return true;
        }
        // 递归条件：找下一个机场，有票则继续，递归ture；没票则return false 回溯
        else{
            // 按字母顺序找到达机场
            for(auto& ed : ticketMap[st]){
                // 如果还有票
                if(ed.second) {
                    // 用票
                    path.push_back(st);
                    ed.second--;
                    numTicket--;
                    
                    // 找到一条路径，递归回传true，结束回溯
                    if(backtrack(ed.first, numTicket, ticketMap, path)) return true;

                    // 没找到，回溯继续递归
                    path.pop_back();
                    ed.second++;
                    numTicket++;
                }
            }
            // 没票: 回溯到上一个节点
            return false;
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        vector<string> path;
        
        // 嵌套哈希表: 出发机场[无序] -> ( 到达机场[有序] -> 机票数量 )
        map<string, map<string,int>> ticketMap;
        int numTicket = 0;
        for(const auto& ticket : tickets) {
            ticketMap[ticket[0]][ticket[1]]++;
            numTicket++;
        }

        // backtracking: 
        backtrack("JFK", numTicket, ticketMap, path);

        return path;

    }
};

int main() {
    std::vector<std::vector<std::string>> tickets = {
        {"JFK", "SFO"},
        {"JFK", "ATL"},
        {"SFO", "ATL"},
        {"ATL", "JFK"},
        {"ATL", "SFO"}
    };

    for(auto str : Solution().findItinerary(tickets)) cout << str << endl;

    // for(auto& strs : board) {
    //     for(auto& str : strs) cout << str;
    //     cout << endl;
    // }
}