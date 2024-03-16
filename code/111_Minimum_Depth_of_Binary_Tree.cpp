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
    // 层序遍历
    int minDepth(TreeNode* root) {

        int layer = 0;
        // 剪枝
        if (root == nullptr) return layer;
        // 否则queue层序遍历
        else {
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()) {
                
                // 层数+1
                layer++;

                // 遍历当前层节点，有叶节点则返回
                // 否则遍历下一层的节点
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    TreeNode* cur = q.front();
                    q.pop();
                    if(cur->left == nullptr && cur->right == nullptr) return layer;
                    else {
                        if(cur->left != nullptr) q.push(cur->left);
                        if(cur->right != nullptr) q.push(cur->right);
                    }
                }
            }
        }

        return -1;  // 逻辑上用不到，为了应付编译
        

    }


};


int main(){

    TreeNode node15(15);
    TreeNode node7(7);
    TreeNode node20(20, &node15, &node7);
    TreeNode node9(9);
    TreeNode node3(3, &node9, &node20);

    cout << Solution().minDepth(&node3) << endl;

}