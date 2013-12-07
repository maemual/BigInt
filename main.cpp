#include"BigInt.h"
#include<iostream>

int main()
{
    BigInt b1(12), b2("123"), b3, b4;
    b3 = "123";
    b4 = b3 * b3;
    std::cout << "b1 = " << b1 << std::endl;
    std::cout << "b2 = " << b2 << std::endl;
    std::cout << "b3 = " << b3 << std::endl;
    std::cout << "b4 = " << b4 << std::endl;

    b1 = b4 / b3;
    std::cout << b1 << std::endl;

    b1 += b2;
    std::cout << "b1 += b2 -> b1 = " << b1 << std::endl;
    b1 -= b2;
    std::cout << "b1 -= b2 -> b1 = " << b1 << std::endl;
    b1 -= b2;
    std::cout << "b1 -= b2 -> b1 = " << b1 << std::endl;

    b1 *= b2;
    std::cout << "b1 *= b2 -> b1 = " << b1 << std::endl;

    b1 *= b1;
    std::cout << "b1 *= b1 -> b1 = " << b1 << std::endl;

    if (b1 > b2)
        std::cout << "b1 > b2" << std::endl;
    else
        std::cout << "b1 <= b2" << std::endl;

    b1++;
    std::cout << "b1++ -> b1 = " << b1 << std::endl;
    b1--;
    std::cout << "b1-- -> b1 = " << b1 << std::endl;
    --b1;
    std::cout << "--b1 -> b1 = " << b1 << std::endl;
    ++b1;
    std::cout << "++b1 -> b1 = " << b1 << std::endl;

    -b1;
    std::cout << "-b1 = " << b1 << std::endl;

    if (b1 == b2)
        std::cout << "b1 == b2" << std::endl;
    else
        std::cout << "b1 != b2" << std::endl;

    b1 = pow(b2, 2);
    std::cout << "b1 = pow(b2, 2) = " << b1 << std::endl;
    b3 = "15129";
    b2 = "123";
    b4 = b3 / b2;
    std::cout << "b1 = b1 / b2 = " << b4 << std::endl;
    std::cout << b2 << std::endl;
    return 0;
}
