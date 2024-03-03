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

class MyLinkedList {
public:

    // class members
    int size;
    ListNode* head;

    // class methods
    MyLinkedList() {
        size = 0;
        head = nullptr;
    }
    
    int get(int index) {
        // illegal, return -1
        if(index < 0 || index >= size){
            return -1;
        } 
        // return the val of the index_th node
        else{
            ListNode* current = head;
            // note: move intex times to the required node
            for(int i = 0; i < index; i++) current = current->next;
            return current->val;
        }

    }
    
    void addAtHead(int val) {
        head = new ListNode(val, head);
        size++;
    }
    
    void addAtTail(int val) {

        if (size == 0){
            head = new ListNode(val, head);
        }
        else{
            ListNode* current = head;
            // move size - 1 times to the last node
            for(int i = 0; i < size - 1; i++) current = current->next;
            // add new node
            current->next = new ListNode(val);
        }        
        size++;
    }
    
    void addAtIndex(int index, int val) {

        // skip illegal call
        // add at head
        if(index <= 0){
            head = new ListNode(val, head);
            size++;
        }
        // add behind the index-1 node
        else if (index <= size) {
            ListNode* current = head;
            
            for(int i = 0; i < index - 1; i++) current = current->next;
            // add new node
            current->next = new ListNode(val, current->next);
            size++;
        }

    }
    
    void deleteAtIndex(int index) {
        // skip illegal call
        if(index >= 0 && index < size){
            
            if (index == 0){

                // delete the first node;
                auto ptr_for_delete = head;
                head = head->next;
                delete ptr_for_delete;
                ptr_for_delete = nullptr;
                
            }
            else{
                // note: move intex - 1 times to the node before the node oughted to be removed (when size>=2)
                auto current = head;
                for(int i = 0; i < index - 1; i++) current = current->next;
                
                // delete
                auto ptr_for_delete = current->next;
                current->next = current->next->next;
                delete ptr_for_delete;
                ptr_for_delete = nullptr;
                
            }
            size--;

        } 

    }


};

void print_list(ListNode* head){
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


// testing
int main() {

    // MyLinkedList myLinkedList = new MyLinkedList();
    MyLinkedList myLinkedList;
    print_list(myLinkedList.head);
    myLinkedList.addAtHead(1);
    print_list(myLinkedList.head);
    myLinkedList.addAtTail(3);
    print_list(myLinkedList.head);
    myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
    print_list(myLinkedList.head);
    cout << myLinkedList.get(1) << endl;              // return 2
    myLinkedList.deleteAtIndex(0);    // now the linked list is 2->3
    print_list(myLinkedList.head);
    cout << myLinkedList.get(0) << endl;              // return 2

}