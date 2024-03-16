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

    // 递归 判断二叉树是否bounded
    bool isBounded(TreeNode* root, long long lower, long long upper) {
        
        // 终止条件：空节点返回true，违背bound返回false
        if(!root) return true;
        else if(root->val >= upper || root->val <= lower) return false;
        // 递归条件：当前节点bounded(已判断) + 子树bounded
        else return isBounded(root->left, lower, root->val) && isBounded(root->right, root->val, upper);

    }

    bool isValidBST(TreeNode* root) {
        return isBounded(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};

int main() {

    // TreeNode node15(15);
    // TreeNode node7(7);
    // TreeNode node20(20, &node15, &node7);
    // TreeNode node9(9);
    // TreeNode node3(3, &node9, &node20);

    // TreeNode node4(4);
    // TreeNode node2(2, nullptr, &node4);
    // TreeNode node3(3);
    // TreeNode node1(1, &node3, nullptr);
    // TreeNode node5(5,new TreeNode(10), nullptr);

    TreeNode node5(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));

    cout << Solution().isValidBST(&node5) << endl;
}