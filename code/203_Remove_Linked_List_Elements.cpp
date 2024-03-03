#include <iostream>
#include <vector>

using namespace std;

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
    ListNode* removeElements(ListNode* head, int val) {

        // a pointer to the head pointer
        ListNode** check_ptr = &head;
        
        // delete or move to the next node if there exist one
        while(*check_ptr != nullptr){
            // delete
            if ((*check_ptr)->val == val){
                ListNode* ptr_for_delete = *check_ptr;
                *check_ptr = (*check_ptr)->next;
                delete ptr_for_delete;
            }
            // move
            else{
                check_ptr = & ((*check_ptr)->next);
            }
        }
        // return head ptr
        return head;



    }
};

// testing
int main() {
    vector<int> nums = {6,1,2,6,3,4,5,6};
    // vector<int> nums = {6};
    int val = 6;
    ListNode* head = list_head(nums);
    print_list(head);
    
    ListNode* head_new = Solution().removeElements(head, val);
    print_list(head_new);

}

