//
// Created by 刘丰恺 on 2018/11/6.
//

using json_object = rapidjson::Value;
using document = rapidjson::Document;

static json_object &parse(char *input) {
    document doc;
    doc.Parse(input);
    return doc;
}

