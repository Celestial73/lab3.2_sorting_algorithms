#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QString>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <sstream>

#include "../data/Student.h"
#include "../data/DataGenerator.h"
#include "../containers/Sequence.h"
#include "../containers/ListSequence.hpp"

#include  "../sorting/BubbleSorter.h"
#include  "../sorting/InsertionSorter.h"
#include  "../sorting/ShellSorter.h"
#include  "../sorting/QuickSorter.h"

#include "../utility/SortUtils.h"

class SortingApp : public QWidget {
    Q_OBJECT

public:
    SortingApp(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Sorting Application");

        auto *layout = new QVBoxLayout(this);

        // Input field for sequence size
        auto *inputLayout = new QHBoxLayout();
        QLabel *sizeLabel = new QLabel("Sequence Size:", this);
        sizeInput = new QLineEdit(this);
        inputLayout->addWidget(sizeLabel);
        inputLayout->addWidget(sizeInput);
        layout->addLayout(inputLayout);

        // Generate Sequence Button
        generateButton = new QPushButton("Generate Sequence", this);
        layout->addWidget(generateButton);

        // Text field to show the generated sequence
        generatedSequenceText = new QTextEdit(this);
        generatedSequenceText->setReadOnly(true);
        layout->addWidget(generatedSequenceText);

        // Sorting buttons
        auto *sortingLayout = new QHBoxLayout();
        quickSortButton = new QPushButton("Quick Sort", this);
        shellSortButton = new QPushButton("Shell Sort", this);
        bubbleSortButton = new QPushButton("Bubble Sort", this);
        insertionSortButton = new QPushButton("Insertion Sort", this);
        sortingLayout->addWidget(quickSortButton);
        sortingLayout->addWidget(shellSortButton);
        sortingLayout->addWidget(bubbleSortButton);
        sortingLayout->addWidget(insertionSortButton);
        layout->addLayout(sortingLayout);

        // Text field to show the sorted sequence
        sortedSequenceText = new QTextEdit(this);
        sortedSequenceText->setReadOnly(true);
        layout->addWidget(sortedSequenceText);

        // Compare Sorts Button
        compareButton = new QPushButton("Compare Sorts", this);
        layout->addWidget(compareButton);

        // Connect signals to slots
        connect(generateButton, &QPushButton::clicked, this, &SortingApp::generateSequence);
        connect(quickSortButton, &QPushButton::clicked, this, &SortingApp::quickSort);
        connect(shellSortButton, &QPushButton::clicked, this, &SortingApp::shellSort);
        connect(bubbleSortButton, &QPushButton::clicked, this, &SortingApp::bubbleSort);
        connect(insertionSortButton, &QPushButton::clicked, this, &SortingApp::insertionSort);
        connect(compareButton, &QPushButton::clicked, this, &SortingApp::compareSorts);
    }

private slots:
    void generateSequence() {
        bool ok;
        int size = sizeInput->text().toInt(&ok);
        if (!ok || size <= 0) {
            generatedSequenceText->setText("Invalid size.");
            return;
        }
        UniquePtr<ds::Sequence<Student>> newSequence(new ds::ListSequence<Student>());
        sequence = std::move(newSequence);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> ageDis(18, 25);
        std::uniform_real_distribution<> scoreDis(2.0, 5.0);
        std::uniform_int_distribution<> courseDis(1, 4);

        for (int i = 0; i < size; ++i) {
            sequence->append( Student(
                "Name" + std::to_string(i + 1),
                "Surname" + std::to_string(i + 1),
                courseDis(gen),
                ageDis(gen),
                scoreDis(gen)));
        }

        generatedSequenceText->setText(sequenceToString(sequence));
        sortedSequenceText->clear();
    }

    void quickSort() {
        QuickSorter<Student> sorter = QuickSorter<Student>();

        auto sorted = sequence->copy();
        sorter.sort(sorted, Student::compareByAverageScore);
        sortedSequenceText->setText(sequenceToString(sorted));
    }

    void shellSort() {
        ShellSorter<Student> sorter = ShellSorter<Student>();

        auto sorted = sequence->copy();
        sorter.sort(sorted, Student::compareByAverageScore);
        sortedSequenceText->setText(sequenceToString(sorted));
    }

    void bubbleSort() {
        BubbleSorter<Student> sorter = BubbleSorter<Student>();

        auto sorted = sequence->copy();
        sorter.sort(sorted, Student::compareByAverageScore);
        sortedSequenceText->setText(sequenceToString(sorted));
    }

    void insertionSort() {
        InsertionSorter<Student> sorter = InsertionSorter<Student>();

        auto sorted = sequence->copy();
        sorter.sort(sorted, Student::compareByAverageScore);
        sortedSequenceText->setText(sequenceToString(sorted));
    }

    void compareSorts() {
        QuickSorter<Student> quickSorter = QuickSorter<Student>();
        auto quickSortSample = sequence->copy();
        auto quickTime = SortUtils<Student>::sortDuration(quickSortSample, quickSorter,Student::compareByAverageScore);
        quickSortSample.release();

        ShellSorter<Student> shellSorter = ShellSorter<Student>();
        auto shellSortSample = sequence->copy();
        auto shellTime = SortUtils<Student>::sortDuration(shellSortSample, shellSorter,Student::compareByAverageScore);
        shellSortSample.release();


        BubbleSorter<Student> bubbleSorter = BubbleSorter<Student>();
        auto bubbleSortSample = sequence->copy();
        auto bubbleTime = SortUtils<Student>::sortDuration(bubbleSortSample, bubbleSorter,Student::compareByAverageScore);
        bubbleSortSample.release();

        InsertionSorter<Student> insertionSorter = InsertionSorter<Student>();
        auto insertionSortSample = sequence->copy();
        auto insertionTime = SortUtils<Student>::sortDuration(insertionSortSample, insertionSorter,Student::compareByAverageScore);
        insertionSortSample.release();


        std::ostringstream result;
        result << "Quick Sort: " << quickTime.count()  << " us\n"
               << "Shell Sort: " << shellTime.count() << " us\n"
               << "Bubble Sort: " << bubbleTime.count()<< " us\n"
               << "Insertion Sort: "<< insertionTime.count()  << " us";

        sortedSequenceText->setText(QString::fromStdString(result.str()));
    }

private:
    UniquePtr<ds::Sequence<Student>> sequence;

    QLineEdit *sizeInput;
    QPushButton *generateButton;
    QTextEdit *generatedSequenceText;
    QPushButton *quickSortButton;
    QPushButton *shellSortButton;
    QPushButton *bubbleSortButton;
    QPushButton *insertionSortButton;
    QTextEdit *sortedSequenceText;
    QPushButton *compareButton;

    QString sequenceToString( UniquePtr<ds::Sequence<Student>> &seq) {
        std::ostringstream oss;
        for (size_t i = 0; i < seq->getLength(); ++i) {
            if (i > 0) oss << "\n";
            Student student = seq->get(i);
            oss << "Name: " << student.getName() << ", Surname: " << student.getSurname()
                << ", Course: " << student.getCourse() << ", Age: " << student.getAge()
                << ", Average Score: " << student.getAverageScore();
        }
        return QString::fromStdString(oss.str());
    }
};

