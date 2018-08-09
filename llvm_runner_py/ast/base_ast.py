import json
from typing import List


class AstNode:
    load_json = None

    def __init__(self, load_json) -> None:
        super().__init__()
        self.load_json = load_json

    def get_tag(self) -> json:
        return self.load_json['tag']


class AstLeaf(AstNode):

    def __init__(self, load_json) -> None:
        super().__init__(load_json)

    def get_token(self) -> json:
        return self.load_json['token']

    def get_text(self) -> str:
        return self.get_token()['text']


class AstList(AstNode):
    children: List[AstNode] = None

    def __init__(self, load_json, children) -> None:
        super().__init__(load_json)
        self.children = children

    def get_children(self) -> List[AstNode]:
        return self.children
