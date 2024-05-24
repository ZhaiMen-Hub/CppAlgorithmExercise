#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int pow(int x, int n){

    // stop cases
    if(n==0) return 1;
    else if(n==1) return x;

    // recursive cases
    else {
        int a = pow(x, n/2);
        if (n % 2 == 0) {
            return a * a;
        }
        else if (n % 2 == 1) {
            return a * a * x;
        }

        else {
            std::cout << "running error" << std::endl;
            return -1;
        }
    }

}

int main()
{
    // std::cout << "Hello World" << std::endl;
    std::cout << pow(3,0) << std::endl;
    std::cout << pow(3,1) << std::endl;
    std::cout << pow(3,2) << std::endl;
    std::cout << pow(3,3) << std::endl;

    priority_queue<pair<int,int>,
                     vector<pair<int,int>>,
                     greater<pair<int,int>>> pq;

    priority_queue<pair<int,pair<int,int>>,
                     vector<pair<int,pair<int,int>>>,
                     greater<pair<int,pair<int,int>>>> pq2;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq3;
    
    pq2.push(make_pair(1,make_pair(2,3)));
    pq2.push(make_pair(4,make_pair(3,2)));
    pq2.push(make_pair(2,make_pair(4,1)));
    pq2.push(make_pair(3,make_pair(5,0)));

    while(!pq2.empty()){
        
        std::cout << pq2.top().first << " " << pq2.top().second.first << " " << pq2.top().second.second << std::endl;
        pq2.pop();
    }
}