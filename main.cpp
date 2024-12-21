#include "utility/GUI.h"
#include "tests/TestSorts.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SortingApp window;
    window.show();

    testSorts();
    testBackwardsDoubleSort();
    testStudentComparators();
    return app.exec();
}