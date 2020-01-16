#include "hobby.tab.hpp"

extern "C" int yylex();

int main(int argc, char **argv) {
    yylex();
    return 0;
}