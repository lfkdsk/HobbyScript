from ast.base_ast import *


class BinaryExpr(AstList):
    def __init__(self, load_json) -> None:
        super().__init__(load_json)

    def get_left(self) -> AstNode:
        return self.children[0]

    def get_right(self) -> AstNode:
        return self.children[2]

    def get_op(self) -> AstNode:
        return self.children[1]
