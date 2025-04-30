#pragma once
#include <vector>
#include <utility>

namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(std::vector<T>& v) {
    const unsigned int n = v.size();
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n - i - 1; ++j) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

template<Sortable T>
void HeapSort(std::vector<T>& v) {
    const unsigned int n = v.size();

    // Build max heap
    for (int start = n / 2 - 1; start >= 0; --start) {
        unsigned int root = start;
        while (2 * root + 1 < n) {
            const unsigned int child = 2 * root + 1;
            unsigned int swapIdx = root;

            if (v[swapIdx] < v[child])
                swapIdx = child;
            if (child + 1 < n && v[swapIdx] < v[child + 1])
                swapIdx = child + 1;

            if (swapIdx == root)
                break;

            std::swap(v[root], v[swapIdx]);
            root = swapIdx;
        }
    }

    // Extract elements from heap
    for (unsigned int end = n - 1; end > 0; --end) {
        std::swap(v[0], v[end]);

        unsigned int root = 0;
        const unsigned int size = end;
        while (2 * root + 1 < size) {
            const unsigned int child = 2 * root + 1;
            unsigned int swapIdx = root;

            if (v[swapIdx] < v[child])
                swapIdx = child;
            if (child + 1 < size && v[swapIdx] < v[child + 1])
                swapIdx = child + 1;

            if (swapIdx == root)
                break;

            std::swap(v[root], v[swapIdx]);
            root = swapIdx;
        }
    }
}

} 



