#pragma once
#include "../containers/Sequence.h"
#include "../pointers/UniquePtr.h"
#include <iostream>
#include <memory>

void printSequence(std::shared_ptr<ds::Sequence<int>>& sequence);
void printSequence(UniquePtr<ds::Sequence<int>> &sequence);