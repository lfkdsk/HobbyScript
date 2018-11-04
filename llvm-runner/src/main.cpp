#include <iostream>
#include <fstream>
#include "spdlog/spdlog.h"
#include "json.hpp"
#include "unitcpp/UnitTest++.h"
#include "visitor/AstVisitor.h"
#include "spdlog/sinks/stdout_sinks.h"

using json = nlohmann::json;

int main(int, const char *[]) {
//    std::ifstream input("../result.ast");
//    for (std::string line; getline(input, line);) {
//        json inputJson = json::parse(line);
//        std::cout << inputJson.dump(4) << std::endl;
//        AstVisitor visitor(inputJson);
//    }

    return UnitTest::RunAllTests();
}
