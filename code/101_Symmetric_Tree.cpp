#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        // 剪枝
        if(root == nullptr) return true;

        // 左侧左中右，右侧中右左，一个一个比较
        stack<TreeNode*> stL, stR;
        stL.push(root->left);
        stR.push(root->right);

        while(!stL.empty()) {
            TreeNode* l = stL.top();
            stL.pop();
            TreeNode* r = stR.top();
            stR.pop();
        
            // 仅一方不为空，return false
            // 均为空或(不为空)数值相等，则continue；否则false
            if (l == nullptr && r != nullptr || l != nullptr && r == nullptr) {
                return false;
            }
            else {
                // 均非空，比较数值，压入子节点
                if (l != nullptr && r != nullptr) {
                    if(l->val != r-> val) return false;
                    else {
                        stL.push(l->right);
                        stL.push(l->left);
                        stR.push(r->left);
                        stR.push(r->right);
                    }
                }
            } 
        }

        return true;

    }
};


int main(){

    // TreeNode node3(3);
    // TreeNode node2(2, &node3, nullptr);
    // TreeNode node1(1,nullptr,&node2);

    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3, &node1, &node2);

    cout << Solution().isSymmetric(&node3) << endl;

    
    // for(int num : Solution().preorderTraversal(Solution().invertTree(&node3))) cout << num;
    // cout << endl;

}