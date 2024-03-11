#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {

    }
    
    void rotate() {
        // 将q的front size - 1 个元素移到下面，相当于将back移到top
        for(int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {

        // 将最后一个元素转上来
        rotate();

        // 返回并移除元素
        int result = q.front();
        q.pop();
        return result;

    }
    
    int top() {

        // 将最后一个元素转上来
        rotate();

        // 返回并塞回元素（还原队列）
        int result = q.front();
        q.pop();
        q.push(result);
        return result;

    }
    
    bool empty() {
        return q.empty();
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
    MyStack* obj = new MyStack();

    obj->push(3);
    obj->push(4);

    int param_2 = obj->pop();

    int param_3 = obj->top();

    bool param_4 = obj->empty();

    cout << param_2 << param_3 << param_4 << endl;
    

}