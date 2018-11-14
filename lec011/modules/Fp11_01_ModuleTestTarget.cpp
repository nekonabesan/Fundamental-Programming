#include "CppUTest/CommandLineTestRunner.h"
#include "Fp11_01_TestTarget.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "fp11_01_module.c"

// テストグループを定義
TEST_GROUP(TestFuncGroup)
{
    // 各テストケースの実行直前に呼ばれる仮想メソッド
    TEST_SETUP()
    {
        std::cout << " TEST_SETUP called" << std::endl;
    }

    // 各テストケースの実行直後に呼ばれる仮想メソッド
    TEST_TEARDOWN()
    {
        std::cout << " TEST_TEARDOWN called" << std::endl;
    }
};

// テストを実行するメソッド
TEST(TestFuncGroup, a)
{
    std::cout << "a" << std::endl;
    double ret = a(10, 10);
    CHECK_EQUAL(10, ret);
}

// テストを実行するメソッド
TEST(TestFuncGroup, b)
{
    std::cout << "b" << std::endl;
    double ret = b(10);
    CHECK_EQUAL(20, ret);
}
