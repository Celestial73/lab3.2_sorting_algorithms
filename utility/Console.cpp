#include "Console.h"


void printSequence(std::shared_ptr<ds::Sequence<int>>& sequence) {
    for (int i = 0; i < sequence->getLength(); i++) {
        std::cout << sequence->get(i) << " ";
    }
}

void printSequence(UniquePtr<ds::Sequence<int>>& sequence) {
    for (int i = 0; i < sequence->getLength(); i++) {
        std::cout << sequence->get(i) << " ";
    }
}
