#pragma once

#include "Student.h"
#include "../containers/Sequence.h"
#include "../containers/ListSequence.hpp"
#include "../pointers/SharedPtr.h"
#include <fstream>
#include <filesystem>

int generateRandomNumber(int min, int max);

void generateRandomArray(int *arr, int size, int min, int max);

double generateRandomDouble(int min, int max, int accuracy);

Student generateStudent();

void generateStudentArray(Student *arr, int size);

SharedPtr<ds::Sequence<Student>> generateStudentSequence(int size);

void writeStudentSequenceToFile(SharedPtr<ds::Sequence<Student>> seq,  const std::string &filename);

SharedPtr<ds::Sequence<Student>>  readStudentSequenceFromFile(const std::string &filename);
