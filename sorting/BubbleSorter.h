#pragma once


#include "ISorter.h"

#include "../containers/Sequence.h"
#include "../pointers/UniquePtr.h"

template<class T>
class BubbleSorter : public ISorter<T> {
public:
    void sort(SharedPtr<ds::Sequence<T>> sequence,
              std::function<bool(const T &, const T &)> comp = std::less<T>()) override {
        bubbleSort(sequence, 0, sequence->getLength() -1 , comp);
    }

    void bubbleSort(SharedPtr<ds::Sequence<T>> sequence, int start, int end,
              std::function<bool(const T &, const T &)> comp = std::less<T>())  {
        int n = sequence->getLength();
        bool swapped;

        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (comp(sequence->get(j+1), sequence->get(j))) {
                    sequence->swap(j+1, j);
                    swapped = true;
                }
            }

            // If no two elements were swapped, then break
            if (!swapped)
                break;
        };
    }
};