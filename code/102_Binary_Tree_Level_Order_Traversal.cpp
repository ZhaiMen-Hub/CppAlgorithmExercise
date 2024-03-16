#include <list>
#include <vector>
#include <iostream>
// #include <stack>
#include <queue>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// 遍历
// 相当于通过堆栈实现递归
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        // 建立结果list
        vector<vector<int>> result;        
        
        // 建立层序队列
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            // 遍历当前层
            int size = q.size();
            // 可能有空的，不能指定具体大小
            vector<int> result_layer;
            
            for(int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur != nullptr) {
                    result_layer.push_back(cur->val);
                    q.push(cur->left);
                    q.push(cur->right);
                }
                
            }

            // 如果这一层不全空，加入结果
            if(result_layer.size() > 0) result.push_back(result_layer);

        }

        return result;

    }
};


int main(){

    // TreeNode node3(3);
    // TreeNode node2(2, &node3, nullptr);
    // TreeNode node1(1,nullptr,&node2);

    TreeNode node15(15);
    TreeNode node7(7);
    TreeNode node20(20, &node15, &node7);
    TreeNode node9(9);
    TreeNode node3(3, &node9, &node20);

    for(auto& vec : Solution().levelOrder(&node3)) {
        for (auto& num : vec) cout << num;
        cout << endl;
    } 

}