#include "hobby.tab.hpp"

extern "C" {
int yylex(void);
int yyparse(void);
void yyerror(const char *error);
}

int main(int argc, char **argv) {
    yyparse();
    return 0;
}