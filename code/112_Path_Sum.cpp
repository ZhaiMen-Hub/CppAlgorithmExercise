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
    bool PathSum(TreeNode* root, int targetSum) {

        // 终止条件：是叶节点
        if (!root->left && !root->right) {
            if(root->val == targetSum) return true;
            else return false;
        }
        else {
            // 如果是空的就短路返回false
            // 其中一个是true就返回
            bool left =  root->left && PathSum(root->left, targetSum - root->val);
            if(left) return true;
            bool right = root->right && PathSum(root->right, targetSum - root->val);
            if(right) return true;
            return false;

            // 等价写法
            // return root->left && PathSum(root->left, targetSum - root->val) || root->right && PathSum(root->right, targetSum - root->val);
        }
    }
    
    // 递归：存在经过父节点路径 = 存在经过左/右节点的路径，和为 sum - root->val
    // 前序处理
    bool hasPathSum(TreeNode* root, int targetSum) {

        // 空节点剪枝（即使targetSum = 0）也返回false
        if(!root) return false;
        else return PathSum(root, targetSum); // 拆分函数避免重复判断空节点

    }
};

int main(){

    // TreeNode node15(15);
    // TreeNode node7(7);
    // TreeNode node20(20, &node15, &node7);
    // TreeNode node9(9);
    // TreeNode node3(3, &node9, &node20);

    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node1(1, &node2, &node3);

    cout << Solution().hasPathSum(&node1, 5) << endl;
    // for (auto& str : Solution().sumOfLeftLeaves(&node3)) cout << str;
    // cout << endl;

}