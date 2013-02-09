#ifndef MOOGUOR_PARSERBASE_H
#define MOOGUOR_PARSERBASE_H

#include <string>
#include "object.h"
#include "variant.h"

namespace Mooguor {

class ParserBase: public Object {

public:
    virtual ~ParserBase() {}

    virtual Variant parse(const std::string & str) = 0;
};

}

#endif
