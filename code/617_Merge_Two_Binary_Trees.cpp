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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        // 终止条件：一边为空，返回另一边（包括两边为空，返回空指针）
        if(!root1) return root2;
        else if(!root2) return root1; // 其实可以合并到下面，但是不好理解，还是分开写
        // 递归条件：两边不为空，合并节点(合并2到1)，合并节点两子树
        else {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
            return root1;
        }
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

    TreeNode node1(1, new TreeNode(3,new TreeNode(5),nullptr), new TreeNode(2));
    TreeNode node2(2, new TreeNode(1, nullptr, new TreeNode(4)), new TreeNode(3, nullptr, new TreeNode(7)));

    TreeNode* tmp = Solution().mergeTrees(&node1, &node2);
    cout << tmp->val << endl; //用调试器检察树
}