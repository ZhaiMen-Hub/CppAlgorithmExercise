#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>

using namespace std;

class MyGreater {
public:
    bool operator() (const pair<int, int>& l, const pair<int, int>& r) {
        return l.first >= r.first;
    }
};

int main(){
    int N = 7, M = 9;
    // cin >> N >> M;

    // srt -> {<dst, cost>}
    vector<vector<pair<int, int>>> vec(N);
    vector<int> parent(N, -1);
    vector<int> minDist(N, INT_MAX);

    // 这里是边的列表，每个元素是三个整数: 起点，终点，权重
    vector<tuple<int, int, int>> edges = {
        {1, 2, 1}, {1, 3, 4}, {2, 3, 2}, {2, 4, 5},
        {3, 4, 2}, {4, 5, 3}, {2, 6, 4}, {5, 7, 4}, {6, 7, 9}
    };

    // 添加边到邻接表
    for (const auto& [u, v, w] : edges) {
        vec[u-1].push_back(make_pair(v-1, w));
        // 如果这是无向图，你需要取消注释下面这行:
        // adj[v].push_back(make_pair(u, w));
    }

    // 输出邻接表
    for (int i = 0; i < vec.size(); i++) {
        cout << "Node " << i << " has edges to: ";
        for (const auto& [neighbor, weight] : vec[i]) {
            cout << "(" << neighbor << ", " << weight << ") ";
        }
        cout << endl;
    }

    // for(int i = 0; i < M; i++) {
    //     int srt, dst, cost;
    //     cin >> srt >> dst >> cost;
    //     vec[srt - 1].push_back({dst - 1, cost});
    //     // cout << vec[srt - 1].back().first << vec[srt - 1].back().second << endl;
    // }
    // // for(int i = 0 ; i < N; i++) cout << vec[i].size() << endl;
    
    
    // queue: value, point
    priority_queue<pair<int, int>, deque<pair<int, int>> , MyGreater> q;
    // push {dis, index}
    q.push({0, 0});

    while(!q.empty()) {
        // 弹出节点
        auto cur = q.top();
        const int& curIndex = cur.second, curDist = cur.first;
        q.pop();
        // cout << curIndex << curDist << endl;
        // cout << vec[curIndex].size() << endl;

        // 更新能去的节点
        for(const auto& neighbor : vec[curIndex]) {
            
            const int& neighborIndex = neighbor.first, neighborDist = neighbor.second;
            // cout << neighborIndex << neighborDist << endl;
            // 如果更近就更新父节点和距离，并重新插入
            if(curDist + neighborDist < minDist[neighborIndex]) {
                // cout << curDist + neighborDist <<  neighborIndex << endl;
                q.push(pair<int,int>{curDist + neighborDist, neighborIndex});
                minDist[neighborIndex] = curDist + neighborDist;
                parent[neighborIndex] = curIndex;
            }
               
        } 

        if(curIndex == N - 1) break; // 找到最优路径了（更新完才结束，兼容D*）
    }
    
    if(parent.back() == -1) cout << -1;
    else {
        int cur = N - 1; // 终止节点
        cout << "MinCost: " << minDist[cur] << endl;
        while(cur != -1) {
            // cout << parent[cur];
            cout << cur;
            cur = parent[cur];
        }
    }

}