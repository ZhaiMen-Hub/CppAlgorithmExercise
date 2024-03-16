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
    void construstPaths(TreeNode* root, string path, vector<string>& paths) {

        // 终止条件：叶节点
        path += to_string(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            paths.push_back(path);
        }
        // 递归条件：子节点路径 = 父节点路径 + 子节点数值 + "->"
        else {
            path += "->";
            if(root->left != nullptr) construstPaths(root->left, path, paths);
            if(root->right != nullptr) construstPaths(root->right, path, paths);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> result;
        string path;

        // 剪枝：空指针不入栈
        if (root == nullptr) return result;
        // 
        else {
            construstPaths(root, path, result);
            return result;
        }
    }
};

int main(){

    TreeNode node15(15);
    TreeNode node7(7);
    TreeNode node20(20, &node15, &node7);
    TreeNode node9(9);
    TreeNode node3(3, &node20, &node9);

    // cout << Solution().isBalanced(&node3) << endl;
    for (auto& str : Solution().binaryTreePaths(&node3)) cout << str;
    cout << endl;

}