#include <iostream>

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
}