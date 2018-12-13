#include "CppUTest/CommandLineTestRunner.h"
#include "Fp11_01_TestTarget.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../../modules/fp11_01_module.c"

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
    DOUBLES_EQUAL(20.90, 20.99, a(2.0, 5.0));
}

// テストを実行するメソッド
TEST(TestFuncGroup, b)
{
    std::cout << "b" << std::endl;
    DOUBLES_EQUAL(2.0, 2.0, b(4.0));
}
