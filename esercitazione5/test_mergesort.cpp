#include <iostream>
#include <vector>
#include <string>
#include "ord.h"      // Deve contenere merge_sort e is_sorted_vec
#include "randfiller.h"

int main() {
    randfiller rf;
    
    for (int i = 0; i < 100; ++i) {
        int size = rand() % 100 + 1; 
        std::vector<int> v(size);
        
        rf.fill(v, -1000, 1000); 
        
        merge_sort(v, 0, (int)v.size() - 1);
         
        if (!is_sorted_vec(v)) {
            std::cerr << "Errore: vettore di interi non ordinato!" << std::endl;
            return EXIT_FAILURE; 
        }
    }

    std::vector<std::string> vs = {
        "mela", "pera", "banana", "arancia", "kiwi", 
        "uva", "limone", "ciliegia", "pesca", "ananas"
    };
    
    merge_sort(vs, 0, (int)vs.size() - 1);
    
    if (!is_sorted_vec(vs)) {
        std::cerr << "Errore: vettore di stringhe non ordinato!" << std::endl;
        return EXIT_FAILURE;
    }
 
    std::cout << "Test Mergesort superato con successo!" << std::endl;
    return EXIT_SUCCESS;
}