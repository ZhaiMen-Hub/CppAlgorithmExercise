# include<iostream>
# include<vector>

using namespace std;

//连续的会议室时间合并

/* 如何会议室的使用时间区段，如 {1,4}, {2, 3}, {5, 5}, {6, 8}, {7, 8}, {9,11} 将重叠的或者连续的区段合并，那么结果是[1,4] [5,5] [6,8] [9,11]。
注意：时间区段的开始时间是有序并且是升序，所以不需要考虑排序问题。

由于题目较简单，主要考察短时间代码书写能力和边界条件考虑情况。
尽量在原地执行，即在原数组上合并。

如C++
void merge(vector<vector<int>>& arr) {

}

示例1：in: 空; out: 空
示例2：in: [1, 2]; out: [1, 2]
示例3：in: {1,4}, {2, 3}, {4, 4}, {5, 5}, {6, 8}, {7, 8}, {9,11}; out:[1,4] [5,5] [6,8] [9,11]
*/

void merge(vector<vector<int>>& arr) {
    
    
    if(arr.size() == 0) return;

    int mergingIndex = 0;
    int toMergeIndex = 1;
    while(toMergeIndex < arr.size()) {
        // 合并to Merge到mergingIndex / 复制到mergingIndex + 1
        if(arr[mergingIndex][1] >= arr[toMergeIndex][0]) {
            // 合并
            arr[mergingIndex][1] = max(arr[mergingIndex][1], arr[toMergeIndex][1]);
            toMergeIndex++;
        }
        else {
            // 移动
            mergingIndex++;
            arr[mergingIndex] = arr[toMergeIndex];
            toMergeIndex++;
        }
    }
    arr.resize(mergingIndex + 1);
}

int main() {
    
    // data
    vector<vector<int>> data = {{1,4}, {2, 3}, {4, 4}, {5, 5}, {6, 8}, {7, 8}, {9,11}};

    merge(data);

    for(const auto & seg : data) {
        for(const auto& num : seg) cout << num; 
        cout << endl;
    }

}