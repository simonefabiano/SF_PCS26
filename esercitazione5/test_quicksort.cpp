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
        rf.fill(v, -500, 500);
        quick_sort(v, 0, v.size() - 1);
        if (!is_sorted_vec(v)) return EXIT_FAILURE;
    }
    
    std::vector<std::string> vs = {"z", "a", "m", "b", "c"};
    quick_sort(vs, 0, vs.size() - 1);
    if (!is_sorted_vec(vs)) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}