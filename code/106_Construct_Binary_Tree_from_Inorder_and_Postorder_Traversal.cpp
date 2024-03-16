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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // 终止条件：数组长度为0，返回空指针
        if(!inorder.size()) return nullptr;
        // 递归条件：切分数组构造子树
        else {
            int rootVal = *postorder.rbegin();
            // 切割数组
            for(int i = 0; i < inorder.size(); i++) {
                if(inorder[i] == rootVal) {

                    // 切割前序
                    vector<int> inorderL(inorder.begin(), inorder.begin() + i);
                    vector<int> inorderR(inorder.begin() + i + 1, inorder.end());
                    // 切割后序
                    vector<int> postorderL(postorder.begin(), postorder.begin() + i);
                    vector<int> postorderR(postorder.begin() + i, postorder.end() - 1);
                    // 递归创造树
                    return new TreeNode(rootVal, buildTree(inorderL, postorderL), buildTree(inorderR, postorderR));
                }
            }
        }
        return nullptr; // 用不到
    }
};

int main() {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    cout << Solution().buildTree(inorder, postorder)->val << endl; //用调试器检察树
}