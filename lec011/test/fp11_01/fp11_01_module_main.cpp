#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

int main(int argc, char* argv[])
{
    // CppUTest起動
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
