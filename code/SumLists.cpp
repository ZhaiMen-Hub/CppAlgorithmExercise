#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <math.h>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    void addNode(ListNode* l1, ListNode* l2, ListNode** sumListP, int carry)
    {
        if(l1 == nullptr && l2 == nullptr && carry == 0) return; //base case
        else {
            int sum = carry;
            if(l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;   
            }
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* res = new ListNode(digit);
            *sumListP = res;
            addNode(l1, l2, &(res->next), carry);
        }

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sumList;
        addNode(l1, l2, &sumList, 0);
        return sumList;
    }
};

int main() {
    ListNode List1(2, new ListNode(4, new ListNode(3)));
    ListNode List2(5, new ListNode(6, new ListNode(4)));
    // ListNode List1(5);
    // ListNode List2(5);
    Solution s;
    ListNode* res = s.addTwoNumbers(&List1, &List2);
    cout << res->val << " " << res->next->val << " " << res->next->next->val << endl;
    return 0;

}