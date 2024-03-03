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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // cal length
        ListNode* cur_1 = headA;
        ListNode* cur_2 = headB;
        int lenA = 0, lenB = 0;
        while (cur_1 != nullptr) {
            cur_1 = cur_1->next;
            lenA++;
        }
        while (cur_2 != nullptr) {
            cur_2 = cur_2->next;
            lenB++;
        }

        // name the longer list as 'headA'
        if (lenA < lenB){
            ListNode* p_tmp = headA;
            int len_tmp = lenA;
            headA = headB;
            headB = p_tmp;
            lenA = lenB;
            lenB = len_tmp;
        }

        // move headA
        for(int i = 0; i < lenA-lenB; i++) headA = headA->next;

        // find intersection
        while(headA != nullptr){
            if (headA == headB) return headA;
            else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return headA;
    }
};

// testing
int main() {
    
    // vector<int> nums_1 = {4,1,8,4,5};
    vector<int> nums = {5,0,1,8,4,5};
    
    ListNode* head_1 = list_head(nums);
    print_list(head_1);
    ListNode* head_2 = head_1->next;
    print_list(head_2);
    
    ListNode* head_new = Solution().getIntersectionNode(head_1, head_2);
    print_list(head_new);

}