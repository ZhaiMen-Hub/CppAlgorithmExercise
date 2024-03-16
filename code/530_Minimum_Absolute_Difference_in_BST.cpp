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
    // 中序遍历返回数组
    void dfs(TreeNode* root, vector<int>& val) {
        // 终止条件：空指针（无操作，隐含）
        // 递归条件：左子树遍历 + 当前节点 + 右子树遍历
        if(root) {
            dfs(root->left, val);
            val.push_back(root->val);
            dfs(root->right, val);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        
        // 中序递归遍历
        vector<int> val;
        dfs(root, val);

        // 找最小绝对差
        int diff = val[1]-val[0];
        for(int i = 2; i < val.size(); i++) {
            int diff_cur = val[i] - val[i - 1];
            if(diff_cur < diff) diff = diff_cur;
        }

        return diff;
    }
};

int main() {

    TreeNode node(4,new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(6));

    cout << Solution().getMinimumDifference(&node) << endl;
}