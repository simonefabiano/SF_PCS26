#include <iostream>
#include "classe_rational.hpp"

int main() {
    rational<int> r1(3, 6);
    std::cout << "Semplificazione 3/6: " << r1 << "\n";

    rational<int> a(1, 2);
    rational<int> b(1, 4);


    std::cout << a << " + " << b << " = " << (a + b) << "\n";
    std::cout << a << " - " << b << " = " << (a - b) << "\n";
    std::cout << a << " * " << b << " = " << (a * b) << "\n";
    std::cout << a << " / " << b << " = " << (a / b) << "\n";
 
    rational<int> inf(5, 0);
    rational<int> nan(0, 0);
    std::cout << "Test Inf: " << inf << "\n";
    std::cout << "Test NaN: " << nan << "\n";

    return 0;
}

// IA impiegata per il tentativo di risoluzione (fallito) di problemi segnalati dal compiler che
// impediscono di runnare il programma, e di cui si cercherà una risoluzione nelle vacanze di Pasqua