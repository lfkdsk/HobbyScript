import json
from typing import List
from schematics import Model
from schematics.types import (
    StringType,
    IntType,
    PolyModelType,
    MultiType,
    FloatType,
    ListType,
    ModelType,
)


class Token(Model):
    text = StringType()
    literal = StringType()
    tag = IntType()
    lineNumber = StringType()
    value = FloatType()
    type = StringType()

    def get_tag(self):
        return self.tag

    def get_text(self):
        return self.text

    def get_value(self):
        return self.value

    def get_literal(self):
        return self.literal

    def get_type(self):
        return self.type


class AstNode(Model):
    tag = IntType()
    type = StringType()

    # def __init__(self, load_json) -> None:
    #     super().__init__(raw_data=load_json)
    #     self.load_json = load_json

    def get_tag(self):
        return self.tag

    def get_type(self):
        return self.type


class AstLeaf(AstNode):
    token = ModelType(Token)
    tag = IntType()
    type = StringType()

    # def __init__(self, load_json) -> None:
    #     super().__init__(load_json)

    def get_token(self):
        return self.token

    def get_text(self):
        return self.token.text


class AstList(AstNode):
    children = ListType(PolyModelType(AstNode))

    # def __init__(self, load_json) -> None:
    #     super().__init__(load_json=load_json)

    def get_children(self):
        return self.children

    def children_size(self):
        return len(self.get_children())
