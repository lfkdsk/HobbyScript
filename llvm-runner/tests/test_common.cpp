//
// Created by 刘丰恺 on 20/1/2020.
//

#include "test_common.h"

extern "C" FILE *yyin;
extern "C" int yyparse(void);
const QString TAG = "[Test Common]: ";

AstContext *test_parse(const QString &fileName, llvm::Module *module) {
    // save context.
    auto *old_package = ast_current_package;
    ast_current_package = new AstPackage();
    auto old_line_num = yylineno;
    yylineno = 0;

    // set open file.
    yyin = fopen(fileName.toUtf8().constData(), "r");
    if (!yyin) {
        throw create_runtime_error(TAG + "could not open file name: " + fileName);
    }
    if (0 != yyparse()) {
        throw create_runtime_error(TAG + "parse " + fileName + "error");
    }

    fclose(yyin);

    // restore context;
    auto *now_package = ast_current_package;
    ast_current_package = old_package;
    return global_packages[fileName] = now_package->compile(module);
}

std::ofstream create_test_output(const QString &fileName) {
    return std::ofstream(fileName.toStdString());
}

QString get_graph_gen_path() {
    return get_test_project_dir() + separator + "test_graph_gen";
}

QString get_test_parse_input() {
    return get_test_project_dir() + separator + "test_parse_input";
}
