
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // create hash table based on nums1
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        unordered_set<int> intersection_set;

        // find intersection and insert to unordered_set
        for (int num : nums2) if (nums1_set.find(num) != nums1_set.end()) intersection_set.insert(num);
            
        // return intersection
        return vector<int>(intersection_set.begin(), intersection_set.end());
    }
};


// testing
int main() {
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    
    for (int num : Solution().intersection(nums1, nums2)) cout << num << endl;

}