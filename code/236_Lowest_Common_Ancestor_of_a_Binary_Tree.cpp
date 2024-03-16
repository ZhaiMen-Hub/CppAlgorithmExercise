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
        // 终止条件：空指针/p或者q
        if(!root || root == p || root == q) return root;
        // 递归条件：两边都有则返回root，有一边则返回一边，都没有则返回null
        else {
            TreeNode* l = lowestCommonAncestor(root->left, p, q);
            TreeNode* r = lowestCommonAncestor(root->right, p, q);
            if(l && r) return root;
            else {
                if(l) return l;
                else return r; // 可能是空或非空，合并
            }
        }
    }
};

int main() {

    TreeNode node5(5, new TreeNode(6), new TreeNode(2));
    TreeNode node1(1);
    TreeNode node(3, &node5, &node1);

    cout << Solution().lowestCommonAncestor(&node, &node5, &node1)->val << endl;
}