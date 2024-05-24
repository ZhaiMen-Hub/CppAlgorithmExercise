#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void edit(vector<vector<int>>& m) {
    
    // 记录行列号
    unordered_set<int> col;
    unordered_set<int> row;
    int q = m.size(), p = m[0].size();

    for(int i = 0; i < q; i++) {
        for(int j = 0; j < p; j++) {
            if(m[i][j] == 0) {
                col.insert(j);
                row.insert(i);
            }
        }
    }

    for(int i = 0; i < q; i++) {
        for(int j = 0; j < p; j++) {
            if(row.find(i) != row.end() || col.find(j) != col.end()) {
                m[i][j] = 0;
            }
        }
    }
    
}

int main() {

    

}