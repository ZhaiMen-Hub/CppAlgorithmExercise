#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

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
//     // 递归：后序遍历树 = 遍历左树 + 遍历右数 + 节点
//     void traversal(TreeNode* root, vector<int>& result) {
//         // 终止条件：root == nullptr
//         if(root != nullptr) {
//             traversal(root->left, result);
//             traversal(root->right, result);
//             result.push_back(root->val);
//         }
//     }

//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> result;
//         traversal(root, result);
//         return result;
//     }
// };

// 遍历
// 相当于通过堆栈实现递归，后序 = 前序(左右反转) + reverse
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
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
                // 倒序压入左右节点（要考虑最后反转）
                st.push(cur->left);
                st.push(cur->right);
            }

        }

        reverse(result.begin(), result.end());
        return result;

    }
};

int main(){

    // TreeNode node3(3);
    // TreeNode node2(2, &node3, nullptr);
    // TreeNode node1(1,nullptr,&node2);

    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3, &node1, &node2);


    for(int num : Solution().postorderTraversal(&node3)) cout << num;
    cout << endl;

}