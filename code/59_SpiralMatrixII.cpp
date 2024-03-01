
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        // result 
        vector<vector<int>> res(n, vector<int>(n, 0));
        
        // circle part
        int num_circle = n / 2;
        int count = 1;
        for (int i = 0; i < num_circle; i++){

            int length = n - 1 - i * 2 ;
            // top
            for(int j = 0; j < length; j++){
                res[i][i+j] = count;
                count++ ;     
            }

            // right
            for(int j = 0; j < length; j++){
                res[i+j][i+length] = count;
                count++;
            }

            // bottom
            for(int j = 0; j < length; j++) {
                res[i+length][i+length-j] = count;
                count++;
            }

            // left
            for(int j = 0; j < length; j++) {
                res[i+length-j][i] = count;
                count++;
            }


        }


        // center part
        if (n % 2 == 1) res[n/2][n/2] = count;
        // if (n % 2 == 1) res[n/2+1][n/2+1] = count; // WRONG! 区分长度和坐标

        // return
        return res;
    }
};


// testing
int main() {
    
    int n = 4;

    for (const auto& row : Solution().generateMatrix(n)) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

}