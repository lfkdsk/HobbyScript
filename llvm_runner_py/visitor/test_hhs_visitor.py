import unittest
import json
from visitor.hobbyhorse_visitor import HobbyHorseVisitor
from ast.base_ast import *


class TestHobbyHorseVisitor(unittest.TestCase):
    hhs_visitor: HobbyHorseVisitor = HobbyHorseVisitor()

    @staticmethod
    def create_ast_leaf() -> json:
        leaf = json.loads(r'{"token": {"text": "+", "lineNumber": 1, "tag": 264}, "tag": 264, "type": "AstLeaf"}')
        return leaf

    def test_visitor_ast_leaf(self):
        leaf = json.loads(r'{"token": {"text": "+", "lineNumber": 1, "tag": 264}, "tag": 264, "type": "AstLeaf"}')
        ast_leaf: AstLeaf = self.hhs_visitor.visit(leaf)
        self.assertIsNotNone(ast_leaf)
        self.assertEqual('+', ast_leaf.get_text())
        self.assertEqual(264, ast_leaf.get_tag())
