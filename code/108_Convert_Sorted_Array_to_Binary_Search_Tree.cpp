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
    TreeNode* array2BST(auto it, int count) {
        
        // 终止条件：空数组
        if(!count) return nullptr;
        else {
            // 分割数组（长度向下取整，count = 1 则 left = right = 0
            int countL = (count - 1) / 2;
            int countR = count - 1 - countL;
            // 递归创造
            // 用第countL+1个数(下标为countL)创造节点
            return new TreeNode(*(it + countL), array2BST(it, countL), array2BST(it + countL + 1, countR));
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return array2BST(nums.begin(), nums.size());
    }
};

int main() {

    vector<int> nums = {-10,-3,0,5,9,10};

    cout << Solution().sortedArrayToBST(nums)->val << endl;
}