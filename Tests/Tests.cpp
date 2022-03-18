#include <gtest/gtest.h>
#include <fstream>

extern "C" {
#include "../Headers/histogram.h"
#include "../Headers/bar_graph.h"
}

class TestVector : public ::testing::Test {
protected:
    histogram *vector{};

    void SetUp() {
        vector = histogram_constructor(0);
    }

    void TearDown() {
        for (int i = 0; i < vector->size; ++i) {
            //free(vector->arrayPointers[i]);
            free(vector->arrayCounter[i]);
        }
        free(vector->arrayCounter);
        free(vector->arrayPointers);
        free(vector);
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
        histogram_append(vector, &a[i]);
        ASSERT_EQ(&a[i], vector->arrayPointers[i]);
        ASSERT_EQ(1, *vector->arrayCounter[i]);
    }
}

TEST_F(TestVector, extend) {
    const int size = 5;
    int a[size];
    for (int i = 0; i < size; ++i) {
        a[i] = i;
        histogram_append(vector, &a[i]);
    }
    ASSERT_EQ(5, vector->size);
    ASSERT_EQ(7, vector->maxSize);
}

class TestBarGraph : public ::testing::Test {
};

TEST_F(TestBarGraph, unique_element_index) {
    histogram *vector = histogram_constructor(0);
    const int size = 5;
    int a[size];
    for (int i = 0; i < size; ++i) {
        a[i] = i;
        histogram_append(vector, &a[i]);
    }
    ASSERT_EQ(2, unique_element_index(2, vector));
    ASSERT_EQ(-1, unique_element_index(20, vector));
    for (int i = 0; i < size; ++i) {
        free(vector->arrayCounter[i]);
    }
    free(vector->arrayCounter);
    free(vector->arrayPointers);
    free(vector);
}


TEST_F(TestBarGraph, get_bar_graph) {
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
    int ***result = get_bar_graph(array, &size);
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
    for (int i = 0; i < size; ++i) {
        free(result[1][i]);
    }
    free(result[0]);
    free(result[1]);
    free(result);
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
