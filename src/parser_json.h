#ifndef MOOGUOR_PARSER_JSON_H
#define MOOGUOR_PARSER_JSON_H

#include <string>
#include <json/json.h>
#include "object.h"
#include "parserbase.h"

namespace Mooguor {
namespace Parser {

class JSON: public ParserBase {
public:
    virtual Variant parse(const std::string & str);

private:
    Variant parse(json_object * obj);
};

}
}

#endif
