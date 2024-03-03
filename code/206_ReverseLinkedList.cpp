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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* back = nullptr;   // pointer to the node before current node (pointed by head)
        ListNode* temp_swap = nullptr;
        // use head as a iterator
        while(head != nullptr){
            // swap: head->next <- back <- head <- head->next
            // note that should not edit head before head->next
            cout << head->val << endl;
            temp_swap = head->next;
            head->next = back;
            back = head;
            head = temp_swap;
        }
        // when head = nullptr, back point to the last node
        return back;
    }
};

// testing
int main() {
    vector<int> nums = {1,2,6,3,4,5,6};
    // vector<int> nums = {6};
    int val = 6;
    ListNode* head = list_head(nums);
    print_list(head);
    
    ListNode* head_new = Solution().reverseList(head);
    print_list(head_new);

}