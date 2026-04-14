#include <iostream>
#include <vector>
#include <algorithm>
#include "ord.h"
#include "randfiller.h"
#include "timecounter.h"

int main() {
    randfiller rf;
    timecounter tc;
    
    std::cout << "Size\tBubble\tInsert\tSelect\tstd::sort" << std::endl;

    for (int n : {4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192}) {
        std::vector<int> base(n);
        rf.fill(base, 0, 10000);

        std::cout << n << "\t";

        auto v = base;
        tc.tic();
        bubble_sort(v);
        std::cout << tc.toc() << "\t";

        auto v = base;
        tc.tic();
        insertion_sort(v);
        std::cout << tc.toc() << "\t";

        auto v = base;
        tc.tic();
        selection_sort(v);
        std::cout << tc.toc() << "\t"

        v = base;
        tc.tic();
        std::sort(v.begin(), v.end());
        std::cout << tc.toc() << std::endl;
    }
    return 0;
}

// Usata AI per scheletro base del codice da cui studiare, dovuto al tempo limitato per lo svolgimento dell'esercitazione a causa di
// motivi di salute. Si provvederà al recupero