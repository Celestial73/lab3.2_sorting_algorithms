
#include "TestSorts.h"

#include <map>

#include "../data/DataGenerator.h"

void testSorter(SharedPtr<ISorter<int>> sorter, string sortName) {
    int size = 100;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    srand(seed);

    int* items = new int[size];
    for (int i = 0; i < size; i++) {
        items[i] = rand() % 100;
    }
    SharedPtr<ds::Sequence<int>> sequence = SharedPtr<ds::Sequence<int>>(new ds::ListSequence<int>(items, size));
    cout << "\n" << sortName << " SORT: \n";
    cout << "Original Sequence: ";
    printSequence(sequence);

    auto sortSample = sequence->copy();
    auto insertionTime = SortUtils<int>::sortDuration(sortSample, sorter);


    cout << "\nSorted Sequence: \n";
    printSequence(sortSample);
    for (int i = 0; i < size; i++) {
        if (sortSample->get(i) > sortSample->get(i)) {
            throw std::logic_error("sort error");
        }
    }
    delete[] items;
    cout << "\n";
}


void testSorts() {
    map<std::string, SharedPtr<ISorter<int>>> sorts = {
        {"QUICK", SharedPtr<ISorter<int>>(new QuickSorter<int>())},
        {"SHELL", SharedPtr<ISorter<int>>(new ShellSorter<int>())},
        {"BUBBLE", SharedPtr<ISorter<int>>(new BubbleSorter<int>())},
        {"INSERTION", SharedPtr<ISorter<int>>(new InsertionSorter<int>())}
        };

    for (auto const& [key, val] : sorts)
    {
        testSorter(val, key);
    }
}

bool inverseDoubleCompare(const double& a, const double& b) {
    return a > b;
}

void testBackwardsDoubleSort() {
    int size = 500;

    double* items = new double[size];
    for (int i = 0; i < size; i++) {
        items[i] = generateRandomDouble(1, 10000, 3);
    }

    SharedPtr<ds::Sequence<double>> sequence = SharedPtr<ds::Sequence<double>>(new ds::ListSequence(items, size));
    cout << "\n Testing inverse double sorting: \n";
    cout << "Original Sequence: ";
    printSequence(sequence);

    SharedPtr<ISorter<double>> sorter(new QuickSorter<double>());
    auto sortSample = sequence->copy();
    auto insertionTime = SortUtils<double>::sortDuration(sortSample, sorter, inverseDoubleCompare);


    cout << "\nSorted Sequence: \n";
    printSequence(sortSample);
    for (int i = 1; i < size - 1; i++) {
        if (sortSample->get(i) < sortSample->get(i + 1)) {
            throw std::logic_error("inverse double sort error");
        }
    }
    delete[] items;
    cout << "\n";
}


void testStudentComparators() {
    int size = 100;

    Student* items = new Student[size];
    for (int i = 0; i < size; i++) {
        items[i] = generateStudent();
    }
    SharedPtr<ds::Sequence<Student>> sequence = SharedPtr<ds::Sequence<Student>>(new ds::ListSequence(items, size));
    cout << "\n Testing different student comparators: \n";
    cout << "Original Sequence: ";
    printSequence(sequence);

    map<std::string, std::function<bool(const Student & a, const Student & b)>> comparisons = {
        {"AGE", Student::compareByAge},
        {"GRADE", Student::compareByAverageScore},
        {"COURSE", Student::compareByCourse},
    };
    SharedPtr<ISorter<Student>> sorter(new QuickSorter<Student>());
    for (auto const& [key, val] : comparisons)
    {
        cout << "\n Testing " << key << " comparator: \n";
        auto sortSample = sequence->copy();
        auto sortTime = SortUtils<Student>::sortDuration(sortSample, sorter, val);
        cout << "\n Sequence after sorting by " << key << "\n";
        printSequence(sortSample);
        for (int i = 0; i < size - 1; i++) {
            if (val(sortSample->get(i+1), sortSample->get(i))) {
                throw std::logic_error("sort error");
            }
        }
    }
}