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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        // 终止条件：root指向节点为空或为所求节点
        // 迭代条件：选择左指针/右指针继续迭代
        TreeNode* cur = root;
        while(cur && cur->val != val ) {
            if(cur->val < val) cur = cur->right;
            else cur = cur->left;
        }
        return cur;
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

    // TreeNode node1(1, new TreeNode(3,new TreeNode(5),nullptr), new TreeNode(2));
    TreeNode node4(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7));

    TreeNode* tmp = Solution().searchBST(&node4, 2);
    cout << tmp->val << endl; //用调试器检察树
}