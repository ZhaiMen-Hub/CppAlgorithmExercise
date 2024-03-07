#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        // 构建数组哈希表
        int hash['z' - 'a' + 1] = {0};

        // 统计 magazine
        for(const auto& c : magazine) hash[c - 'a']++;

        // 扣除 ransomNote (是否>=0)
        for(const auto& c : ransomNote){
            hash[c - 'a']--;
            if (hash[c - 'a'] < 0) {
                return false;
            }
        }
        return true;

    }
};


// testing

int main(){

    string s = "aa", t = "aab";
    cout << Solution().canConstruct(s,t) << endl;

}