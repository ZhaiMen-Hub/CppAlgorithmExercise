#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    // vector<int> tree{1, 2, 3, 4, 5, 6, 7};
    vector<int> tree{1, 2, 4, 6};
    vector<int> layerOrder;
    queue<pair<int, int>> q;
    q.push(make_pair(0, tree.size() - 1));
    // midOrder2layerOrder(tree, q, layerOrder);
    
    while(!q.empty()) {
        auto [left, right] = q.front();
        q.pop();
        
        // // 满二叉树
        // int mid = left + (right - left) / 2;
        // layerOrder.push_back(tree[mid]);
        // if(left != right) {
        //     q.push(make_pair(left, mid - 1));
        //     q.push(make_pair(mid + 1, right));
        // }

        // 完全二叉树
        // layer = 1
        if(left == right) {
            layerOrder.push_back(tree[left]);
        }
        // layer >= 2
        else {
            int numLayer = 2;
            while(pow(2, numLayer) - 1 < right - left + 1) numLayer++;
            int less = pow(2, numLayer) - 1 - (right - left + 1);
            int leftless;
            if(less > pow(2, numLayer - 2)) {
                leftless = less - pow(2, numLayer - 2);
            } else {
                leftless = 0;
            }
            int mid = pow(2, numLayer - 1) - 1 - leftless;
            layerOrder.push_back(tree[mid]);
            if(left < mid) q.push(make_pair(left, mid - 1));
            if(mid < right) q.push(make_pair(mid + 1, right));
        }


    }
    for (int i = 0; i < layerOrder.size(); i++) {
    }
    for (int i = 0; i < layerOrder.size(); i++) {
        cout << layerOrder[i] << " ";
    }
    cout << endl;
    return 0;
}