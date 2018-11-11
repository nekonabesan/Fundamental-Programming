#include "CppUTest/CommandLineTestRunner.h"
#include "fp11_03_TestTerget.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../../modules/fp11_03_module.c"

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
TEST(TestFuncGroup, calc1)
{
    std::cout << "calc1" << std::endl;
    double ret = calc1(10.0);
    CHECK_EQUAL(3.16228, ret);
}
