//
// Created by 刘丰恺 on 21/1/2020.
//

#include <gtest/gtest.h>
#include <fstream>
#include "common/gen_graph.h"
#include "parser/object.h"
#include "test_common.h"

TEST(MY_TEST, GRAPH_GEN_0) {
    auto *node = createNode(QString("test_node_0").toUtf8().data());
    auto of = create_test_output(get_graph_gen_path() + separator + "test_node_0.gv");
    gen_one_dot_node(of, *node);
}