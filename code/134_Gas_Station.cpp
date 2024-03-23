#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int sumMin = 0;
        int minIndex = -1; // stIndex = minIndex + 1
        for(int i = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            if(sum < sumMin) {
                sumMin = sum;
                minIndex = i;
            }
        }
        if(sum < 0) return -1;
        else return minIndex + 1; // sum > 0 > minSum, 因此 i != size - 1
    }
};


int main() {
    vector<int> gas = {1,2,3,4,5}, cost = {3,4,5,1,2};
    cout << Solution().canCompleteCircuit(gas, cost) << endl;

}