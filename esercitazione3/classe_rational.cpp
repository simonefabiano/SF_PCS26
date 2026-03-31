#include <iostream>
#include "classe_rational.hpp"

int main() {
    rational<int> r(3, 6);
    std::cout << "Frazione semplificata: " << r << std::endl;

    rational<int> a(1, 4);
    rational<int> b(1, 4);
    rational<int> c = a + b;
    
    std::cout << a << " + " << b << " = " << c << std::endl;

    return 0;
}