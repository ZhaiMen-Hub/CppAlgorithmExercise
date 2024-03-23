#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        vector<int> cash(2,0); // 5元和10元的钞票

        for(const auto& bill : bills) {
            switch (bill) {
                case 5:
                    cash[0]++;
                    break;
                case 10:
                    if(cash[0] == 0) return false;
                    else {
                        cash[0]--;
                        cash[1]++;
                    }
                    break;
                case 20:
                    // 找10 + 5 / 5 * 3
                    if(cash[1] != 0) {
                        if(cash[0] == 0) return false;
                        else {
                            cash[1]--;
                            cash[0]--;
                        }
                    }
                    else{
                        if(cash[0] < 3) return false;
                        else cash[0] -= 3;
                    }
                    break;
            }
        }
        return true;
    }
};


int main() {
    vector<int> nums = {5,5,5,10,20};
    cout << Solution().lemonadeChange(nums) << endl;

}