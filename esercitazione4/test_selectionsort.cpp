#include <iostream>
#include <vector>
#include <string>
#include "ord.h"
#include "randfiller.h"

int main() {
    randfiller rf;
    
    for (int i = 0; i < 100; ++i) {
        int size = rand() % 100 + 1;
        std::vector<int> v(size);
        rf.fill(v, -1000, 1000);
        
        selection_sort(v);
        
        if (!is_sorted_vec(v)) {
            return EXIT_FAILURE;
        }
    }

    std::vector<std::string> vs = {"Torino", "Roma", "Milano", "Napoli", "Venezia"};
    selection_sort(vs);
    
    if (!is_sorted_vec(vs)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// Usata AI per scheletro base del codice da cui studiare, dovuto al tempo limitato per lo svolgimento dell'esercitazione a causa di
// motivi di salute. Si provvederà al recupero