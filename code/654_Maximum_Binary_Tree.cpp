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
    TreeNode* constructTree(auto it, int count) {
        
        // 终止条件：空节点
        if(!count) return nullptr;
        // 递归条件：分割数组构造
        else {
            int maxVal = INT_MIN;
            int index = 0;
            // find max
            for(int i = 0; i < count; i++) {
                if(*(it+i) > maxVal) {
                    maxVal = *(it+i);
                    index = i;
                }
            }
            TreeNode* leftNode = constructTree(it, index);
            TreeNode* rightNode = constructTree(it + index + 1, count - index - 1);
            return new TreeNode(maxVal, leftNode, rightNode);

        }
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        // 提高效率：传pos,count
        return constructTree(nums.begin(), nums.size());

    }
};

int main() {
    // vector<int> inorder = {9,3,15,20,7};
    // vector<int> postorder = {9,15,7,20,3};
    vector<int> nums = {3,2,1,6,0,5};
    cout << Solution().constructMaximumBinaryTree(nums)->val << endl; //用调试器检察树
}