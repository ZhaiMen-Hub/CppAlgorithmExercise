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


// 遍历
// 相当于通过堆栈实现递归
class Solution {
public:
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

    // // 递归
    // TreeNode* invertTree(TreeNode* root) {
    //     if (root != nullptr) {
    //         swap(root->left, root->right);
    //         invertTree(root->left);
    //         invertTree(root->right);
    //     }
    //     return root;
    // }

    // 前序遍历
    TreeNode* invertTree(TreeNode* root) {
        
        stack<TreeNode*> st;
        st.push(root);

        TreeNode* cur = nullptr;
        while(!st.empty()) {
            cur = st.top();
            st.pop();
            swap(cur->left, cur->right);
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
        }

        return root;
    }
};


int main(){

    // TreeNode node3(3);
    // TreeNode node2(2, &node3, nullptr);
    // TreeNode node1(1,nullptr,&node2);

    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3, &node1, &node2);

    for(int num : Solution().preorderTraversal(Solution().invertTree(&node3))) cout << num;
    cout << endl;

}