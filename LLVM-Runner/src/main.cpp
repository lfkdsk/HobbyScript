#include <iostream>
#include <nlohmann/json.hpp>
#include <UnitTest++/UnitTest++.h>

using json = nlohmann::json;

int main(int, const char *[]) {
    return UnitTest::RunAllTests();
}
