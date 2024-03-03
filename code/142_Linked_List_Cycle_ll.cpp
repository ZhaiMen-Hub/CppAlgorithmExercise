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
    ListNode *detectCycle(ListNode *head) {
        
        // check it there is a cycle and find meeting point
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {

            fast = fast->next->next;
            slow = slow->next;

            // do not check at the beginning (fast = slow = head)
            if (fast == slow) {

                // find the fork point
                ListNode* meet = fast;
                ListNode* restart = head;
                while(meet != restart) {
                    meet = meet->next;
                    restart = restart->next;
                }
                // return the fork point
                return restart;
            }
        }
        // if fast reach the end, there is no cycle
        return nullptr;
        
    }
};

// testing
int main() {
    
    vector<int> nums = {3,2,0,-4};
    ListNode* head = list_head(nums);
    print_list(head);
    cout << head->next->val << endl;
    cout << head->next->next->next->val << endl;
    head->next->next->next->next = head->next;

    // vector<int> nums = {1};
    // ListNode* head = list_head(nums);
    // print_list(head);
    
    
    ListNode* head_new = Solution().detectCycle(head);
    cout << head_new->val << endl;
    // print_list(head_new);

}