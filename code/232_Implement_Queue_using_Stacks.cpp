#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;

    MyQueue() {

    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    void refresh() {
        // 如果stOut空了，就把stIn倒到stOut里
        if(stOut.empty()) {
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
    }
    
    int pop() {

        // 如果stOut空了，就把stIn倒到stOut里
        refresh();
        // 从stOut取，删除
        int result = stOut.top();
        stOut.pop();
        return result;
    }
    
    int peek() {

        // 如果stOut空了，就把stIn倒到stOut里
        refresh();
        // 从stOut取，不删除
        return stOut.top();
        
    }
    
    bool empty() {

        if(stIn.empty() && stOut.empty()) 
            return true;
        else 
            return false;

    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    MyQueue* obj = new MyQueue();

    obj->push(3);
    obj->push(4);

    int param_2 = obj->pop();

    int param_3 = obj->peek();

    bool param_4 = obj->empty();

    cout << param_2 << param_3 << param_4 << endl;
    

}