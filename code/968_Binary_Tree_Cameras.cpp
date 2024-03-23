#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val, TreeNode* left, TreeNode* right):val(val), left(left), right(right) {};
    TreeNode(int val):val(val), left(nullptr), right(nullptr) {};
    TreeNode(TreeNode* left, TreeNode* right):val(0), left(left), right(right) {};
    TreeNode():val(0), left(nullptr), right(nullptr) {};
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
    int backtrack(TreeNode* root, int& count) {
        // 终止条件：空节点
        if(!root) return 2;
        // 状态转移&返回状态
        else {
            root->val = (min(backtrack(root->left, count), backtrack(root->right, count)) + 1) % 3;
            // 装灯
            if(root->val == 1) count++;
            // 返回状态
            return root->val;
        }
    }
    int minCameraCover(TreeNode* root) {
        
        int count = 0;
        backtrack(root, count);
        // root需要被父节点照亮，则root直接装一个摄像头
        if(root->val == 0) return count + 1;
        else return count;

    }
};

int main() {
    TreeNode root(new TreeNode(new TreeNode(), new TreeNode()), nullptr);
    cout << Solution().minCameraCover(&root) << endl;
}