
#include "TestSorts.h"


void testSorter(ISorter<int>& sorter, string sortName) {
    int size = 100;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    srand(seed);

    int* items = new int[size];
    for (int i = 0; i < size; i++) {
        items[i] = rand() % 100;
    }
    shared_ptr<ds::Sequence<int>> sequence;
    sequence = make_shared<ds::ArraySequence<int>>(items, size);


    cout << "\n" << sortName << " SORT: \n";
    cout << "Original Sequence: ";
    printSequence(sequence);


    auto sortSample = sequence->copy();
    auto insertionTime = SortUtils<int>::sortDuration(sortSample, sorter);


    cout << "\n Sorted Sequence: \n";
    printSequence(sortSample);

    for (int i = 0; i < size; i++) {
        if (sortSample->get(i) > sortSample->get(i)) {
            throw std::logic_error("bubble sort error");
        }
    }
    delete[] items;
    cout << "\n";
}


void testSorts() {
    QuickSorter<int> quickSorter = QuickSorter<int>();
    ShellSorter<int> shellSorter = ShellSorter<int>();
    BubbleSorter<int> bubbleSorter = BubbleSorter<int>();
    InsertionSorter<int> insertionSorter = InsertionSorter<int>();
    testSorter(quickSorter, "QUICK");
    testSorter(shellSorter, "SHELL");
    testSorter(bubbleSorter, "BUBBLE");
    testSorter(insertionSorter, "INSERTION");
}