#pragma once
#include <vector>
#include <algorithm>
#include <limits>

template <typename T>
bool is_sorted_vec(const std::vector<T>& vec) {
    if (vec.empty()) return true;
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] > vec[i + 1]) return false;
    }
    return true;
}

template <typename T>
void bubble_sort(std::vector<T>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (A[j] < A[j - 1]) {
                std::swap(A[j], A[j - 1]);
            }
        }
    }
}

template <typename T>
void insertion_sort(std::vector<T>& A) {
    int n = A.size();
    for (int j = 1; j < n; ++j) {
        T key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}

template <typename T>
void selection_sort(std::vector<T>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(A[i], A[min_idx]);
    }
}

template <typename T>
void merge(std::vector<T>& A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<T> L(n1 + 1), R(n2 + 1);

    for (int i = 0; i < n1; ++i) L[i] = A[p + i];
    for (int j = 0; j < n2; ++j) R[j] = A[q + j + 1];

    if constexpr (std::is_arithmetic_v<T>) {
        L[n1] = std::numeric_limits<T>::max();
        R[n2] = std::numeric_limits<T>::max();
    }

    int i = 0, j = 0;
    for (int k = p; k <= r; ++k) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

template <typename T>
void merge_sort(std::vector<T>& A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

template <typename T>
int partition(std::vector<T>& A, int p, int r) {
    T x = A[r];
    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if (A[j] <= x) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[r]);
    return i + 1;
}

template <typename T>
void quick_sort(std::vector<T>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}