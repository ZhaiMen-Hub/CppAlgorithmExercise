#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class Solution {
public:
    // 高度降序，人数升序
    static bool cmp(const vector<int>& left, const vector<int>& right) {
        // 高度降序
        if(left[0] > right[0]) return true;
        // 人数升序
        else if(left[0] == right[0] && left[1] < right[1]) return true;
        else return false;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        // 高度降序，人数升序
        sort(people.begin(), people.end(), cmp);

        // 链表队列方便插入
        list<vector<int>> que;

        // 链表插入，使用next生成迭代器（链表不能随机搜索，不能begin+n
        for(const auto& person : people) que.insert(next(que.begin(), person[1]), person);

        return vector<vector<int>>(que.begin(), que.end());

        return people;

    }
};


int main() {
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    // cout << Solution().reconstructQueue(people) << endl;

    for(const auto& nums : Solution().reconstructQueue(people)) {
        for(auto num : nums) cout << num;  
        cout << endl;
    }

}