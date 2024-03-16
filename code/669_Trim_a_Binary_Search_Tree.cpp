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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        // 终止条件：空节点
        if(!root) return nullptr;
        // 递归条件：
        else {
            // 删除当前节点，剪对应子树并返回
            if (root->val < low) return trimBST(root->right, low, high);
            else if (root->val > high) return trimBST(root->left, low, high);
            // 保留当前节点，剪两边子树
            else {
                root->left = trimBST(root->left, low, high);
                root->right = trimBST(root->right, low, high);
                return root;
            }
        }
    }
};

int main() {

    TreeNode node5(5, new TreeNode(4), new TreeNode(6));
    TreeNode node1(1);
    TreeNode node(3, &node1, &node5);

    cout << Solution().trimBST(&node, 0, 5)->right->right << endl;
}