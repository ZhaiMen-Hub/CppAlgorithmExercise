#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // create hash table based on string s
        int hash_tbl['z' - 'a' + 1] = {0};

        for (char letter_s : s) hash_tbl[letter_s-'a']++;

        // check whether s contains all letters in s
        for (char letter_t : t) hash_tbl[letter_t-'a']--;

        for (int hash : hash_tbl) if (hash != 0) return false;
        return true;
    }
};


// testing

int main(){

    string s = "anagram", t = "nagaram";
    cout << Solution().isAnagram(s,t) << endl;

}