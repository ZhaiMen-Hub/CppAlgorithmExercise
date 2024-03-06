#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int bitSquaredSum(int n) {
        int sum = 0;
        while(n != 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {

        // create hash table
        unordered_set<int> sum_set = {n};

        // record sum
        while(n != 1) {

            // bit-wise squared sum
            n = bitSquaredSum(n);

            // If n is in the set, then the program has entered a loop.
            if (sum_set.find(n) != sum_set.end())
                return false;
            // else add n to the set
            else 
                sum_set.insert(n);
        }
        // n is happy number
        return true;

    }
};

// test
int main() {
    int val = 19;
    
    cout << Solution().isHappy(val) << endl;

}