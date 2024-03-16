#include<iostream>
#include<vector>

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
    
    TreeNode* deleteNode(TreeNode* root, int key) {

        // 搜索节点

        // 用指针兼容修改root的情况
        TreeNode** cur_p = &root;
        // 每次循环保证cur = *cur_p，最后再更新cur_p
        // 注意不能声明为引用，要跟着cur_p变化
        TreeNode* cur = *cur_p;
        // 终止条件：找到/不存在
        while((cur = *cur_p) && cur->val != key) {
            if(cur->val < key) cur_p = &(cur->right);
            else cur_p = &(cur->left);
        }

        // 删除节点(如果找到)
        // 修改只能用指针操作，cur是复制出来的
        if(cur = *cur_p) {
            // 如果只有一边有(或者都没有)，取有的一边，否则合并
            if(cur->left && cur->right) {
                TreeNode* insert = cur->right;
                while(insert->left) insert = insert->left; // 找到右子树最左的节点
                insert->left = cur->left; // 左子树插到右子树
                *cur_p = cur->right; // 删除节点，连到右子树
            }
            else {
                if(cur->left) *cur_p = cur->left;
                else *cur_p = cur->right;
            }
        } 

        // 返回删除后的树
        return root;

    }
};

int main() {

    TreeNode node5(5, new TreeNode(4), new TreeNode(6));
    TreeNode node1(1);
    TreeNode node(3, &node1, &node5);

    cout << Solution().deleteNode(&node, 5)->right->val << endl;
}