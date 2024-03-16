#include<iostream>
#include<vector>

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

    vector<int> result;
    // 按照题目范围，不会取到pre
    int pre = INT_MIN, count = 0, maxCount = 0;

    // 节点计数
    void update(int val) {

        // 更新计数
        // 重置计数
        if(val != pre) {
            count = 1;
            pre = val;
        }
        // 继续计数
        else {
            count++;
        }

        // 更新列表
        // 添加列表
        if (count == maxCount) result.push_back(val);
        // 重置列表
        else if (count > maxCount) {
            maxCount = count;
            result.clear();
            result.push_back(val);
        }
    }

    // 中序递归遍历节点（并计数）
    // 空节点入栈
    void dfs(TreeNode* root) {
        // 终止条件：空节点（无操作隐去）
        if(root) {
            dfs(root->left);
            update(root->val);
            dfs(root->right);
        }

    }
    vector<int> findMode(TreeNode* root) {

        dfs(root);
        return result;

    }
};

int main() {

    TreeNode node(1, nullptr, new TreeNode(2, new TreeNode(2), nullptr));

    for (auto& num : Solution().findMode(&node)) cout << num;
    cout << endl;
    // cout << Solution().findMode(&node) << endl;
}