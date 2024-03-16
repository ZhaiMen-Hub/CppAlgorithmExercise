#include <list>
#include <vector>
#include <iostream>
// #include <stack>
#include <queue>
#include <cmath>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    // 思路：保存当前层值 -> 处理当前层节点 -> 如果下一层为空（即遍历结束），返回当前层的值
    int findBottomLeftValue(TreeNode* root) {   

        // 空节点剪枝
        int result = 0;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            result = q.front()->val;
            for(int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }

        return result;
    }
};

int main(){

    TreeNode node15(15);
    TreeNode node7(7);
    TreeNode node20(20, &node15, &node7);
    TreeNode node9(9);
    TreeNode node3(3, &node9, &node20);

    cout << Solution().findBottomLeftValue(&node3) << endl;
    // for (auto& str : Solution().sumOfLeftLeaves(&node3)) cout << str;
    // cout << endl;

}