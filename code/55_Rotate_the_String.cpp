#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int k;
    string s;
    // cin >> k >> s ;
    k = 2;
    s = "abcdefg";

    
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin()+k);
    reverse(s.begin()+k, s.end());

    cout << s << endl;


}