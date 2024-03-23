#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {

        vector<int> candies(ratings.size(), 1);
        int result = 0;

        // 左更新
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
        }

        // 右更新
        for(int i = ratings.size() - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) candies[i] = max(candies[i + 1] + 1, candies[i]);

        }

        // 求和
        for(const auto& can : candies) result += can;
        
        return result;

    }
};


int main() {
    vector<int> rating = {1,0,2};
    cout << Solution().candy(rating) << endl;

}