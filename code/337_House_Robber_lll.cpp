#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val, TreeNode* left, TreeNode* right):val(val), left(left), right(right) {};
    TreeNode(int val):val(val), left(nullptr), right(nullptr) {};
    TreeNode(TreeNode* left, TreeNode* right):val(0), left(left), right(right) {};
    TreeNode():val(0), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    vector<int> backtrack(TreeNode* root) {
        vector<int> dp(2, 0); // 不选/选
        
        // 终止条件：空节点
        if(root == nullptr) return dp; // 偷不偷都是0
        // 递归条件：选择当前点/不选择
        else {
            vector<int> left = backtrack(root->left);
            vector<int> right = backtrack(root->right);

            // 不选，返回左右节点的最大值之和
            dp[0] = max(left[0], left[1]) + max(right[0], right[1]);

            // 选
            // dp[1] = max(root->val + left[0] + right[0], dp[0]);
            dp[1] = root->val + left[0] + right[0];

            return dp;
        }
    }
    int rob(TreeNode* root) {
        vector<int> dp = backtrack(root);
        return max(dp[0], dp[1]);
    }
};

int main() {
    TreeNode root(3, new TreeNode(2, nullptr, new TreeNode(3)), new TreeNode(3, nullptr, new TreeNode(1)));
    cout << Solution().rob(&root) << endl;
}