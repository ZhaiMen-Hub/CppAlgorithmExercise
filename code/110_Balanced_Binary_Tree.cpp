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
    int getHeight(TreeNode* root) {
        
        int lHeight = 0, rHeight = 0;
        
        // 终止条件：空指针返回0
        if (root == nullptr) return 0;
        // 递归条件：如果两边平衡且高度差<=1, 返回max+1，否则返回-1
        else {

            // 如果一侧不平衡，返回-1
            // 利用 || 短路特性剪枝，如果一侧不平衡不需要算另一侧
            if ((lHeight = getHeight(root->left)) == -1 || (rHeight = getHeight(root->right)) == -1) return -1;
            // 平衡则返回高度，否则返回-1
            else return abs(lHeight - rHeight) > 1 ? -1 : max(lHeight, rHeight) + 1;

            // // 上面等价于下面这段
            // int lHeight = getHeight(root->left);
            // if(lHeight == -1) return -1;
            // int rHeight = getHeight(root->right);
            // if(rHeight == -1) return -1;

            // // 平衡则返回高度，否则返回-1
            // return abs(lHeight - rHeight) > 1 ? -1 : max(lHeight, rHeight) + 1;

        }
        
        
    }
    
    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};


int main(){

    TreeNode node15(15);
    TreeNode node7(7);
    TreeNode node20(20, &node15, &node7);
    TreeNode node9(9);
    TreeNode node3(3, &node20, &node9);

    cout << Solution().isBalanced(&node3) << endl;

}