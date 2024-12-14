#pragma once

#include "ISorter.h"
#include "../pointers/UniquePtr.h"

template<class T>
class InsertionSorter : public ISorter<T> {
public:
    void sort(UniquePtr<ds::Sequence<T>> &sequence,
              std::function<bool(const T &, const T &)> comp = std::less<T>()) override {
        insertionSort(sequence, 0, sequence->getLength() -1 , comp);
    }

    void insertionSort(UniquePtr<ds::Sequence<T>> &sequence , int low, int high,
              std::function<bool(const T &, const T &)> comp = std::less<T>()) {
        for (auto i = low + 1; i != high; ++i) {
            int size = sequence->getLength();
            for (int i = 1; i < size; i++) {
                T key = sequence->get(i);
                int j = i - 1;

                while (j >= 0 && comp(key,sequence->get(j))) {
                    sequence->set(j + 1, sequence->get(j));
                    j--;
                }

                sequence->set(j + 1, key);
            }
        }
    }


};