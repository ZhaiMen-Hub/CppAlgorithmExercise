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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        // 终止条件：空节点
        if(!root) return new TreeNode(val);
        // 递归条件：插入到子树（如果是空节点，会通过返回值修改指针，否则返回原指针）
        else {
            if(root->val < val) root->right = insertIntoBST(root->right, val);
            else root->left = insertIntoBST(root->left, val);
            return root;
        }
    }
};

int main() {

    TreeNode node5(5, new TreeNode(4), new TreeNode(6));
    TreeNode node1(1);
    TreeNode node(3, &node1, &node5);

    cout << Solution().insertIntoBST(&node, 2)->val << endl;
}