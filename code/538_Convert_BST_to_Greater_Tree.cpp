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
    int pre = 0;
    void inorder(TreeNode* root) {

        // 中序遍历，空节点不入栈

        // 右
        if(root->right) inorder(root->right);
        // 中
        pre = root->val += pre; // 同一优先级，从右到左
        // 左
        if(root->left) inorder(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        
        // 非空则处理
        if(root) inorder(root);

        // 返回处理后的树（合并了空树的情况）
        return root;
    }
};

int main() {

    TreeNode node5(5, new TreeNode(4), new TreeNode(6));
    TreeNode node1(1);
    TreeNode node(3, &node1, &node5);

    cout << Solution().convertBST(&node)->val << endl;
}