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

        ListNode* headNode = head;   
        ListNode* nextNode = nullptr;
        // ListNode* next2Node = nullptr;
        ListNode* lastNode = nullptr;
        while(headNode != nullptr){
            
            // save
            nextNode = headNode->next;
            // next2Node = headNode->next->next;

            // swap
            headNode->next = lastNode;
            // headNode->next->next = headNode;

            // update
            lastNode = headNode;
            headNode = nextNode;
        }
        // when head = nullptr, back point to the last node
        return lastNode;
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