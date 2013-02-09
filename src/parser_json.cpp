#include "parser_json.h"
#include "variant_string.h"
#include "variant_list.h"
#include "variant_map.h"
#include <memory>

using namespace Mooguor;
using namespace Mooguor::Parser;

static Variant parseJSON(json_object * obj);

Variant JSON::parse(const std::string & str)
{
    std::shared_ptr<json_object> root(json_tokener_parse(str.c_str()), std::ptr_fun(&json_object_put));

    return parseJSON(root.get());
}

Variant parseObject(json_object * obj)
{
    VariantMap map;

    json_object_object_foreach(obj, key, value) {
        map[key] = parseJSON(value);
    }

    return Variant(map);
}

Variant parseArray(json_object * obj)
{
    VariantList list;

    for (int i = 0; i < json_object_array_length(obj); i++) {
        list.push_back(parseJSON(json_object_array_get_idx(obj, i)));
    }

    return Variant(list);
}

Variant parseJSON(json_object * obj)
{
    switch(json_object_get_type(obj)) {
        case json_type_null:
            return Variant("");
            break;
        case json_type_boolean:
            return Variant(json_object_get_boolean(obj));
            break;
        case json_type_double:
            return Variant(json_object_get_double(obj));
            break;
        case json_type_int:
            return Variant(json_object_get_int(obj));
            break;
        case json_type_object:
            return parseObject(obj);
            break;
        case json_type_array:
            return parseArray(obj);
            break;
        case json_type_string:
            return Variant(json_object_get_string(obj));
            break;
        default:
            return Variant("");
            break;
    }
}
