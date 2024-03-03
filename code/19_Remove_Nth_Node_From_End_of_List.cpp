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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* fast = head;
        ListNode** slow = &head; // mmay be the 1st node will be removed
        
        // fast move n step
        for(int i = 0; i < n; i++) fast = fast->next;

        // move to the end
        while(fast != nullptr){
            fast = fast->next;
            slow = &(*slow)->next;
        }

        // delete the node pointed by *slow
        ListNode* delete_temp = *slow;
        *slow = (*slow)->next;
        delete delete_temp;

        return head;
    }
};

// testing
int main() {
    // vector<int> nums = {1,2,6,3,4,5,6};
    vector<int> nums = {1,2,3};
    int n = 2;
    
    ListNode* head = list_head(nums);
    print_list(head);
    
    ListNode* head_new = Solution().removeNthFromEnd(head, n);
    print_list(head_new);

}