#include <gtest/gtest.h>
#include <fstream>

extern "C" {
#include "../Headers/Vector.h"
#include "../Headers/BarGraph.h"
}

class TestVector : public ::testing::Test {
protected:
    Vector *vector{};

    void SetUp() {
        vector = Vector_constructor(0);
    }

    void TearDown() {
        free(vector->arrayCounter);
        free(vector->arrayPointers);
        Vector_destructor(vector);
    }
};

TEST_F(TestVector, constructor) {
    ASSERT_EQ(vector->size, 0);
    ASSERT_EQ(vector->maxSize, 1);
    ASSERT_EQ(vector->extension, 2);
}

TEST_F(TestVector, append) {
    const int size = 5;
    int a[size];
    for (int i = 0; i < size; ++i) {
        a[i] = i;
        Vector_append(vector, &a[i]);
        ASSERT_EQ(&a[i], vector->arrayPointers[i]);
        ASSERT_EQ(1, *vector->arrayCounter[i]);
    }
}

TEST_F(TestVector, extend) {
    const int size = 5;
    int a[size];
    for (int i = 0; i < size; ++i) {
        a[i] = i;
        Vector_append(vector, &a[i]);
    }
    ASSERT_EQ(5, vector->size);
    ASSERT_EQ(8, vector->maxSize);
}

class TestBarGraph : public ::testing::Test {
protected:
    char *filenameInput;
    char *filenameInputWrong;
    char *filenameOutput;
    char *filenameOutputExpect;

    void SetUp() {
        filenameInput = "/home/killoboker/CLionProjects/untitled/Tests/IO/Input/inputCorrect";
        filenameInputWrong = "/home/killoboker/CLionProjects/untitled/Tests/IO/Input/inputWrong";
        filenameOutput = "/home/killoboker/CLionProjects/untitled/Tests/IO/Output/output";
        filenameOutputExpect = "/home/killoboker/CLionProjects/untitled/Tests/IO/Output/outputExpected";
    }

    void TearDown() {}
};

TEST_F(TestBarGraph, uniqueElementIndex) {
    Vector *vector = Vector_constructor(0);
    const int size = 5;
    int a[size];
    for (int i = 0; i < size; ++i) {
        a[i] = i;
        Vector_append(vector, &a[i]);
    }
    ASSERT_EQ(2, uniqueElementIndex(2, vector));
    ASSERT_EQ(-1, uniqueElementIndex(20, vector));
}

TEST_F(TestBarGraph, scanArray) {
    int **result = scanArray(filenameInput);
    ASSERT_EQ(10, *result[0]);
    int size = *result[0];
    for (int i = 0; i < size - 1; ++i) {
        ASSERT_EQ(i * 2, result[1][i]);
    }
    ASSERT_EQ(0, result[1][size - 1]);
}

TEST_F(TestBarGraph, scanArrayEmpty) {
    int **result = scanArray(filenameInputWrong);
    ASSERT_EQ(nullptr, result);
}

TEST_F(TestBarGraph, getBarGraph) {
    const int constSize = 10;
    int size = constSize;
    int array[constSize] = {1, 1, 2, 1, 3, 4, 5, 6, 90, 0};
    int ***result = getBarGraph(array, &size);
    ASSERT_EQ(&array[0], result[0][0]);
    ASSERT_EQ(&array[2], result[0][1]);
    ASSERT_EQ(&array[4], result[0][2]);
    ASSERT_EQ(&array[5], result[0][3]);
    ASSERT_EQ(&array[6], result[0][4]);
    ASSERT_EQ(&array[7], result[0][5]);
    ASSERT_EQ(&array[8], result[0][6]);
    ASSERT_EQ(&array[9], result[0][7]);

    ASSERT_EQ(3, *result[1][0]);
    ASSERT_EQ(1, *result[1][1]);
    ASSERT_EQ(1, *result[1][2]);
    ASSERT_EQ(1, *result[1][3]);
    ASSERT_EQ(1, *result[1][4]);
    ASSERT_EQ(1, *result[1][5]);
    ASSERT_EQ(1, *result[1][6]);
    ASSERT_EQ(1, *result[1][7]);
}

TEST_F(TestBarGraph, printGraph) {
    int **scannedArray = scanArray(filenameInput);
    int *size = scannedArray[0];
    int ***result = getBarGraph(scannedArray[1], size);
    printGraph(result[1], result[0], *size, filenameOutput);
    std::ifstream output(filenameOutput);
    std::ifstream outputExpect(filenameOutputExpect);
    std::string outputLine;
    std::string outputLineExpected;
    while (std::getline(output, outputLine)) {
        std::getline(outputExpect, outputLineExpected);
        ASSERT_EQ(outputLineExpected, outputLine);
    }

}


int main() {
    testing::InitGoogleTest();
    RUN_ALL_TESTS();
    return 0;
}