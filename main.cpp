#include"BigInt.h"
#include<iostream>

int main()
{
    BigInt b1(15), b2("15");
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    if (b1 == b2)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    //b1 = b2;
    //std::cout << b1 << std::endl;
    //std::cin >> b2;
    //std::cout << b2 << std::endl;
    if (b1 < b2)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    return 0;
}