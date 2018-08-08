import json


class AstNode:
    load_json: json = None

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
    children: list[AstNode] = None

    def __init__(self, load_json, children) -> None:
        super().__init__(load_json)
        self.children = children

    def get_children(self) -> list[AstNode]:
        return self.children
