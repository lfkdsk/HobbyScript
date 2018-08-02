#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "visitor/AstVisitor.h"
#include "UnitTest++/UnitTest++.h"

using json = nlohmann::json;

int main(int, const char *[]) {
    std::ifstream input("../result.ast");
    for (std::string line; getline(input, line);) {
        json inputJson(line);
        std::cout << inputJson.dump(4) << std::endl;
        AstVisitor visitor(inputJson);
    }

    return 0;
}