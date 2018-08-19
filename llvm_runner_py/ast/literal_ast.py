from ast.base_ast import AstLeaf


class NumberLiteral(AstLeaf):

    def get_value(self):
        return self.get_token().get_value()


class StringLiteral(AstLeaf):

    def get_text(self) -> str:
        return self.get_token().get_literal()


class BoolLiteral(AstLeaf):

    def get_bool(self) -> bool:
        if self.get_token().get_type() == 'TRUE':
            return True
        return False


class IDLiteral(AstLeaf):

    def get_text(self) -> str:
        return self.get_token().get_text()
