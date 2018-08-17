import json
from typing import List
from schematics import Model
from schematics.types import StringType, IntType, PolyModelType, FloatType


class Token(Model):
    text = StringType()
    literal = StringType()
    tag = IntType()
    lineNumber = StringType()
    value = FloatType()

    def get_tag(self):
        return self.tag

    def get_text(self):
        return self.text

    def get_value(self):
        return self.value


class AstNode(Model):
    load_json = None
    tag = IntType()

    def __init__(self, load_json) -> None:
        super().__init__(load_json)
        self.load_json = load_json

    def get_tag(self):
        return self.tag


class AstLeaf(AstNode):
    token = PolyModelType(Token)
    tag = IntType()
    type = StringType()

    def __init__(self, load_json) -> None:
        super().__init__(load_json)

    def get_token(self):
        return self.token

    def get_text(self):
        return self.token.text


class AstList(AstNode):
    children: List[AstNode] = None

    def __init__(self, load_json, children) -> None:
        super().__init__(load_json)
        self.children = children

    def get_children(self) -> List[AstNode]:
        return self.children
