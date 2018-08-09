from visitor.base_visitor import Visitor
import json
from typing import Mapping
from ast.base_ast import *

AST_LEAF = 264


class HobbyHorseVisitor(Visitor):
    functions_map: Mapping[int, classmethod]

    def __init__(self) -> None:
        super().__init__()
        self.functions_map = {
            AST_LEAF: self.visit_ast_leaf,
        }

    def visit(self, node: json) -> AstNode:
        super().visit(node)
        tag: int = node['tag']
        return self.functions_map[tag](node)

    def visit_ast_leaf(self, node):
        super().visit_ast_leaf(node)
        return AstLeaf(node)
