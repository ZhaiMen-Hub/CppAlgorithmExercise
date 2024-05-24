// 题目：
// input:
// std::vector<std::pair<double, double> > sv_list; // s from 0 
// double dt;

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void edit(vector<pair<double, double>>& sv_list, double ds) {

    
    // 维护 s, ds 的 单调队列
    // 最小值在最左侧，top弹出
    queue<double> minV;
    for(int i = 0; i < sv_list.size(); i++){
        // update sv_i
        double s_ds = sv_list[i].first + ds;
        double v_min = sv_list[i].second;
        for(int j = i + 1; j < sv_list.size() && sv_list[j].first < s_ds; j++){
            v_min = min(v_min, sv_list[j].second);          
        }
        sv_list[i].second = v_min;
    }
}

int main() {
    vector<pair<double, double>> sv_list = {{}};
    double ds;


    
}