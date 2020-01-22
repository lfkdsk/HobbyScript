//
// Created by 刘丰恺 on 21/1/2020.
//

#include <gtest/gtest.h>
#include <fstream>
#include "common/gen_graph.h"
#include "parser/object.h"
#include "test_common.h"

/**
 * Graph Validate Template.
 * <code>
 *  auto name = "test_node_0";
 *  auto *node = createNode(QString(name).toUtf8().data());
 *  auto test_gen = get_graph_gen_path() + separator + name + ".gv";
 *  auto validate_gen = get_test_graph_gen_validate() + separator + name + ".gv";
 *  auto of = create_test_output(get_graph_gen_path() + separator + name + ".gv");
 * </code>
 */

TEST(MY_TEST, GRAPH_GEN_0) {
    auto name = "test_node_0";
    auto *node = createNode(QString(name).toUtf8().data());
    auto test_gen = get_graph_gen_path() + separator + name + ".gv";
    auto validate_gen = get_test_graph_gen_validate() + separator + name + ".gv";
    auto of = create_test_output(get_graph_gen_path() + separator + name + ".gv");
    gen_one_dot_node(of, *node, true);
    ASSERT_TRUE(compare_file(test_gen.toStdString(), validate_gen.toStdString()));
}