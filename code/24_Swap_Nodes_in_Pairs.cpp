#include <iostream>
#include <vector>

using namespace std;

// define the ListNode struct
struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *list_head(vector<int>& nums){

    ListNode * head_pointer = nullptr;  // ptr to the head
    int length = nums.size();
    // create list reversely
    for(int i = length - 1; i >= 0; i--){
        // ListNode node(nums[i], head_pointer);
        // head_pointer = & node;
        head_pointer = new ListNode(nums[i], head_pointer);
    }
    return head_pointer; // list_head = nullptr when nums.size() = 0
}

void print_list(ListNode* head){
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        // create double pointer, *cur point to the 1st node in a pair
        ListNode** p_cur = &head;

        while (*p_cur != nullptr && (*p_cur)->next != nullptr)
        {
            // avoid redundant dereference
            ListNode*& cur = *p_cur;
            // swap 2 node
            ListNode* cur_next_tmp = cur->next;
            ListNode* cur_next_next_tmp = cur->next->next;

            cur->next->next = cur;
            cur->next = cur_next_next_tmp;
            cur = cur_next_tmp;

            // move to next pair
            p_cur = & cur->next->next;
            
        }
        
        return head;
    }
};

// testing
int main() {
    // vector<int> nums = {1,2,6,3,4,5,6};
    vector<int> nums = {1,2,3};
    
    ListNode* head = list_head(nums);
    print_list(head);
    
    ListNode* head_new = Solution().swapPairs(head);
    print_list(head_new);

}