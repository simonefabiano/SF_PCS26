#include <iostream>
#include <algorithm>
#include <cmath> 

int main() {
    static const int N = 12;
    double arr[N] = {1.5, 2.7, 3.2, 0.9, 4.4, 5.1, 2.2, 3.8, 1.9, 4.0, 6.3, 0.5};
    double minimo = arr[0];
    double massimo = arr[0];
    double somma = 0;

    for (int i = 0; i < N; ++i) {
        minimo = std::min(minimo, arr[i]);
        massimo = std::max(massimo, arr[i]);
        somma = somma + arr[i];
    }

    double media = somma / N;

    double sommaSQ = 0;
    for (int i = 0; i < N; ++i) {
        sommaSQ = sommaSQ + (arr[i] - media) * (arr[i] - media);
    }
 
    double devst = std::sqrt(sommaSQ / N); 

    std::cout << "Minimo:              " << minimo << "\n";
    std::cout << "Massimo:              " << massimo << "\n";
    std::cout << "Media:              " << media << "\n";
    std::cout << "Deviazione Standard:               " << devst << "\n";

    return 0;
}

// Non è stata utilizzata l'IA