#include <list>
#include <vector>
#include <iostream>
// #include <stack>
#include <queue>

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
    // 递归
    int maxDepth(TreeNode* root) {

        // 终止条件
        if (root == nullptr) return 0;
        // 递归条件
        else return max(maxDepth(root->left), maxDepth(root->right)) + 1;

    }

};


int main(){

    TreeNode node15(15);
    TreeNode node7(7);
    TreeNode node20(20, &node15, &node7);
    TreeNode node9(9);
    TreeNode node3(3, &node9, &node20);


    cout << Solution().maxDepth(&node3) << endl;

}