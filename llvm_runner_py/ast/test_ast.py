import unittest
import json
from .base_ast import AstLeaf


class TestAst(unittest.TestCase):

    def test_ast_leaf(self):
        leaf: json = json.loads(r'{"token": {"text": "+", "lineNumber": 1, "tag": 264}, "tag": 264, "type": "AstLeaf"}')
        ast_leaf: AstLeaf = AstLeaf(leaf)
        self.assertEqual(ast_leaf.get_token()['tag'], 264)
        self.assertEqual(ast_leaf.get_token()['text'], '+')
