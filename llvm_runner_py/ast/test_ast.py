import unittest
import json
from ast.base_ast import AstLeaf
from ast.expr_ast import *
from ast.literal_ast import NumberLiteral, StringLiteral


class TestAst(unittest.TestCase):

    def test_ast_leaf(self):
        ast_leaf: AstLeaf = AstLeaf(
            {"token": {"text": "+", "lineNumber": 1, "tag": 264}, "tag": 264, "type": "AstLeaf"}
        )
        self.assertEqual(ast_leaf.get_token().get_tag(), 264)
        self.assertEqual(ast_leaf.get_token().get_text(), '+')

    def test_number_literal(self):
        number_literal: NumberLiteral = NumberLiteral(
            {"token": {"value": 1, "lineNumber": 1, "tag": 270}, "tag": 270, "type": "NumberLiteral"}
        )
        self.assertEqual(number_literal.get_token().get_tag(), 270)
        self.assertEqual(number_literal.get_value(), 1)

    # def test_binary_expr(self):
    #     binary_expr_json = json.loads(
    #         r"""
    #         {
    #             "afterPoint":0,
    #             "children":[
    #                 {
    #                     "token":{
    #                         "value":1,
    #                         "lineNumber":1,
    #                         "tag":270
    #                     },
    #                     "tag":270,
    #                     "type":"NumberLiteral"
    #                 },
    #                 {
    #                     "token":{
    #                         "text":"+",
    #                         "lineNumber":1,
    #                         "tag":264
    #                     },
    #                     "tag":264,
    #                     "type":"AstLeaf"
    #                 },
    #                 {
    #                     "token":{
    #                         "value":1111,
    #                         "lineNumber":1,
    #                         "tag":270
    #                     },
    #                     "tag":270,
    #                     "type":"NumberLiteral"
    #                 }
    #             ],
    #             "tag":279,
    #             "type":"BinaryExpr"
    #         }
    #         """
    #     )
    #
    #     binary_expr: BinaryExpr = BinaryExpr(binary_expr_json)
    #     self.assertEqual(binary_expr.get_tag(), 279)
    #     self.assertEqual(binary_expr.get_children().count(), 3)
    #
