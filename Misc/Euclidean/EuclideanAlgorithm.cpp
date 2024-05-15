/*
Author: Shamik V. Patro
Description: Calculate the GCD between 2 numbers via the Euclidean Algorithm (a = b * q + r).
*/

#include <iostream>
#include <vector>

int main(){

    int a = 0;
    int b = 0;

    std::cout << "Enter your first number: ";
    std::cin >> a;
    std::cout << "Enter your second number: ";
    std::cin >> b;

    int q = a / b;
    int r = a % b;

    std::cout << "The GCD of " << a << " and " << b << " is: ";

    std::vector<int> remainder = {r};

    while (r != 0 || r == 1){

        a = b;
        b = r;
        q = a/b;
        r = a%b;
        remainder.push_back(r);

    }

    remainder.pop_back();
    int gcd = remainder.back();
    std::cout << gcd << std::endl;

    return 0;

}