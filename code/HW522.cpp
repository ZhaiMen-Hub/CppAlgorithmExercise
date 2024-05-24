#include <vector>
#include <string>
#include <iostream>

using namespace std;

string compressStr(const string& str) {
    string result;

    int toCompressIndex = 0;
    for(int i = 0; i < str.length(); i++){

        // compress when the current char is not equal to the previous one
        if( i == str.length() - 1 || str[i+1] != str[toCompressIndex]){
            // compress
            if(i - toCompressIndex == 0){
                result.push_back(str[toCompressIndex]);
            }else{
                result.append(to_string(i - toCompressIndex + 1));
                result.push_back(str[toCompressIndex]);
            }
            // move to next char
            toCompressIndex = i + 1;
        }
    }

    return result;

}

int main() {

    string str = "abcdeefffgg";

    cout << compressStr(str) << endl; 

}