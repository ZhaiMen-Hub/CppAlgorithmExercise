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
//     // 递归：中序遍历树 = 遍历左树 + 节点 + 遍历右树
//     void traversal(TreeNode* root, vector<int>& result) {
//         // 终止条件：root == nullptr
//         if(root != nullptr) {
//             traversal(root->left, result);
//             result.push_back(root->val);
//             traversal(root->right, result);
//         }
//     }

//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         traversal(root, result);
//         return result;
//     }
// };

// 遍历
// 相当于通过堆栈实现递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        // 建立结果vec
        vector<int> result;
        
        // 建立递归堆栈
        stack<TreeNode*> st;

        TreeNode* cur = root;
        while(cur != nullptr || !st.empty()) {

            // 如果非空，压入当前节点，指向左侧节点
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            // 否则弹出节点，处理弹出节点并指向其右侧
            else {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }

        }

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

    for(int num : Solution().inorderTraversal(&node3)) cout << num;
    cout << endl;

}