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
        Vector_partDestructor(vector);
    }
};

TEST_F(TestVector, constructor) {
    ASSERT_EQ(vector->size, 0);
    ASSERT_EQ(vector->maxSize, 0);
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
    ASSERT_EQ(7, vector->maxSize);
}

class TestBarGraph : public ::testing::Test {
protected:
    char *filenameInput;
    char *filenameInputWrong;
    char *filenameOutput;
    char *filenameOutputExpect;

    void SetUp() {
        std::string str = std::string(__FILE__) + "/../IO/Input/inputCorrect";
        filenameInput = strdup(str.c_str());
        str = "../Tests/IO/Input/inputWrong";
        filenameInputWrong = strdup(str.c_str());
        str = "../Tests/IO/Output/output";
        filenameOutput = strdup(str.c_str());
        str = "../Tests/IO/Output/outputExpected";
        filenameOutputExpect = strdup(str.c_str());
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
/*
TEST_F(TestBarGraph, scanArray) {
    int ***result = scanArray(filenameInput);
    ASSERT_EQ(10, **result[0]);
    int size = **result[0];
    for (int i = 0; i < size - 1; ++i) {
        ASSERT_EQ(i * 2, *result[1][i]);
    }
    ASSERT_EQ(0, result[1][size - 1]);
}
*/

TEST_F(TestBarGraph, scanArrayEmpty) {
    FILE *inputWrong = fopen(filenameInputWrong, "r");
    int ***result = scanArray(inputWrong);
    ASSERT_EQ(NULL, result);
    fclose(inputWrong);
}

TEST_F(TestBarGraph, getBarGraph) {
    const int constSize = 10;
    int size = constSize;

    int arr_0 = 1;
    int arr_1 = 1;
    int arr_2 = 2;
    int arr_3 = 1;
    int arr_4 = 3;
    int arr_5 = 4;
    int arr_6 = 5;
    int arr_7 = 6;
    int arr_8 = 90;
    int arr_9 = 0;
    int *array[constSize] = {&arr_0, &arr_1, &arr_2, &arr_3, &arr_4, &arr_5, &arr_6, &arr_7, &arr_8, &arr_9};
    int ***result = getBarGraph(array, &size);
    ASSERT_EQ(array[0], result[0][0]);
    ASSERT_EQ(array[2], result[0][1]);
    ASSERT_EQ(array[4], result[0][2]);
    ASSERT_EQ(array[5], result[0][3]);
    ASSERT_EQ(array[6], result[0][4]);
    ASSERT_EQ(array[7], result[0][5]);
    ASSERT_EQ(array[8], result[0][6]);
    ASSERT_EQ(array[9], result[0][7]);

    ASSERT_EQ(3, *result[1][0]);
    ASSERT_EQ(1, *result[1][1]);
    ASSERT_EQ(1, *result[1][2]);
    ASSERT_EQ(1, *result[1][3]);
    ASSERT_EQ(1, *result[1][4]);
    ASSERT_EQ(1, *result[1][5]);
    ASSERT_EQ(1, *result[1][6]);
    ASSERT_EQ(1, *result[1][7]);
}

/*
TEST_F(TestBarGraph, printGraph) {
    int ***scannedArray = scanArray(filenameInput);
    int ***result = getBarGraph(scannedArray[1], *scannedArray[0]);
    printGraph(result[1], result[0], **scannedArray[0], filenameOutput);
    std::ifstream output(filenameOutput);
    std::ifstream outputExpect(filenameOutputExpect);
    std::string outputLine;
    std::string outputLineExpected;
    while (std::getline(output, outputLine)) {
        std::getline(outputExpect, outputLineExpected);
        ASSERT_EQ(outputLineExpected, outputLine);
    }

}
*/

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
