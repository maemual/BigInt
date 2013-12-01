#include"BigInt.h"
#include<iostream>

int main()
{
    BigInt b1(129), b2("12345");
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    //if (b1 == b2)
    //    std::cout << "Yes" << std::endl;
    //else
    //    std::cout << "No" << std::endl;
    //b1 = b2;
    //std::cout << b1 << std::endl;
    //std::cin >> b2;
    //std::cout << b2 << std::endl;
    //if (b1 > b2)
    //    std::cout << "Yes" << std::endl;
    //else
    //    std::cout << "No" << std::endl;
    std::cout << b1 + b2 << std::endl;
    std::cout << b1 * b2 << std::endl;
    return 0;
}
