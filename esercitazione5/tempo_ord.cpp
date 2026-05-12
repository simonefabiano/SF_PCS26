#include <iostream>
#include <vector>
#include "ord.h"
#include "randfiller.h"
#include "timecounter.h"

int main() {
    randfiller rf;
    timecounter tc;
    const int num_vettori = 100;

    std::cout << "Dim\tBubble\t\tQuick\t\tstd::sort" << std::endl;

    for (int n : {4, 8, 10, 50, 100, 500, 1000}) {
        std::vector<std::vector<int>> dataset(num_vettori, std::vector<int>(n));
        for (auto& v : dataset) rf.fill(v, 0, 10000);

        std::cout << n << "\t";

        auto dataset_copy = dataset;
        tc.tic();
        for (auto& v : dataset_copy) {
            quick_sort(v, 0, n - 1);
        }
        std::cout << tc.toc() / num_vettori << "\t";

    
        dataset_copy = dataset;
        tc.tic();
        for (auto& v : dataset_copy) {
            std::sort(v.begin(), v.end());
        }
        std::cout << tc.toc() / num_vettori << std::endl;
    }
    return 0;
}