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
    int countNodes(TreeNode* root) {

        // 终止条件：最左深度 = 最右深度 => 完全二叉树
        // 包括空指针情况
        int lDepth = 0;
        int rDepth = 0;

        TreeNode* lCur = root;
        while(lCur != nullptr) {
            lDepth++;
            lCur = lCur->left;
        }

        TreeNode* rCur = root;
        while(rCur != nullptr) {
            rDepth++;
            rCur = rCur->right;
        }

        if(lDepth == rDepth) return pow(2, lDepth) - 1;
        else return countNodes(root->left) + countNodes(root->right) + 1;

    }
};


int main(){

    TreeNode node15(15);
    TreeNode node7(7);
    TreeNode node20(20, &node15, &node7);
    TreeNode node9(9);
    TreeNode node3(3, &node20, &node9);

    cout << Solution().countNodes(&node3) << endl;

}