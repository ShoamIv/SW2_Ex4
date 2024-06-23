#ifndef HEAPITERATOR_HPP
#define HEAPITERATOR_HPP

#include <vector>

template <typename T>
class HeapIterator {
private:
    std::vector<T> heap;
    std::size_t currentIndex;

public:
    explicit HeapIterator(const std::vector<T>& heap, std::size_t index = 0)
            : heap(heap), currentIndex(index) {}

    T operator*() const {
        return heap[currentIndex];
    }

    bool operator!=(const HeapIterator& other) const {
        return currentIndex != other.currentIndex;
    }

    HeapIterator& operator++() {
        ++currentIndex;
        return *this;
    }

    static HeapIterator end(const std::vector<T>& heap) {
        return HeapIterator(heap, heap.size());
    }
};

#endif // HEAPITERATOR_HPP
