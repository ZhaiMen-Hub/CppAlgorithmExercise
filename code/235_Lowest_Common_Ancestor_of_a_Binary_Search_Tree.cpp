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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 终止条件：找到 root->val 在 p,q 之间
        // 递归条件：递归左右子树
        // 显然可以迭代实现
        TreeNode* cur = root;
        TreeNode* ancestor = nullptr;

        while(!ancestor) {
            if(cur->val < p->val && cur->val < q->val) cur = cur->right;
            else if(cur->val > p->val && cur->val > q->val) cur = cur->left;
            else ancestor = cur;
        }

        return ancestor;
    }
};

int main() {

    TreeNode node5(5, new TreeNode(4), new TreeNode(6));
    TreeNode node1(1);
    TreeNode node(3, &node1, &node5);

    cout << Solution().lowestCommonAncestor(&node, &node5, &node1)->val << endl;
}