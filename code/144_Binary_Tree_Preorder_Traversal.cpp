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

// // 递归
// class Solution {
// public:
//     // 递归：前序遍历树 = 节点 + 遍历左树 + 遍历右数
//     void traversal(TreeNode* root, vector<int>& result) {
//         // 终止条件：root == nullptr
//         if(root != nullptr) {
//             result.push_back(root->val);
//             traversal(root->left, result);
//             traversal(root->right, result);
//         }
//     }

//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         traversal(root, result);
//         return result;
//     }
// };

// 遍历
// 相当于通过堆栈实现递归
class Solution {
public:
    // 空节点入栈（更简洁自然，比如镜像二叉树）
    vector<int> preorderTraversal(TreeNode* root) {
        
        // 建立结果vec
        vector<int> result;
        
        // 建立递归堆栈
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            // 弹出top节点（中节点）
            TreeNode* cur = st.top();
            st.pop();
            // 处理top节点
            if (cur!=nullptr) {
                result.push_back(cur->val);
                // 倒序压入左右节点
                st.push(cur->right);
                st.push(cur->left);
            }

        }

        return result;

    }

    // 空节点不入栈：效率更高
    // 区别：根节点&左右节点检测，弹出是不用检测
    vector<int> preorderTraversal(TreeNode* root) {
        
        // 建立结果vec
        vector<int> result;
        if (root == nullptr) return result;
        
        // 建立递归堆栈
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            // 弹出top节点（中节点）
            TreeNode* cur = st.top();
            st.pop();
            // 处理top节点
            result.push_back(cur->val);
            // 倒序压入左右节点
            if(cur->right != nullptr) st.push(cur->right);
            if(cur->left != nullptr) st.push(cur->left);

        }

        return result;

    }

};

int main(){

    TreeNode node3(3);
    TreeNode node2(2, &node3, nullptr);
    TreeNode node1(1,nullptr,&node2);

    for(int num : Solution().preorderTraversal(&node1)) cout << num;
    cout << endl;

}