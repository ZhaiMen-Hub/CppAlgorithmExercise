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
    // 递归，空节点不入栈
    // direction: 0-左；1-右
    int leftLeaves(TreeNode* root, bool is_left) {

        // 终止条件：是叶子
        // 左叶子返回值，右叶子返回0
        if (root->left == nullptr && root->right == nullptr) {
            if(is_left) return root->val;
            else return 0;
        }
        // 递归条件：左右之和
        else {
            int l = 0, r = 0;
            if(root->left != nullptr) l = leftLeaves(root->left, true);
            if(root->right != nullptr) r = leftLeaves(root->right, false);
            return l+r;
        }

    }
    
    int sumOfLeftLeaves(TreeNode* root) {

        // 空节点剪枝
        if(root == nullptr) return 0;
        // 将根节点视为右叶子
        else return leftLeaves(root, false);

    }
    
};

int main(){

    TreeNode node15(15);
    TreeNode node7(7);
    TreeNode node20(20, &node15, &node7);
    TreeNode node9(9);
    TreeNode node3(3, &node20, &node9);

    cout << Solution().sumOfLeftLeaves(&node3) << endl;
    // for (auto& str : Solution().sumOfLeftLeaves(&node3)) cout << str;
    // cout << endl;

}