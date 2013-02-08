#ifndef MOOGUOR_REQUEST_H
#define MOOGUOR_REQUEST_H

#include <string>
#include "object.h"

namespace Mooguor {

class Request: public Object {
    std::string type;
    std::vector<std::string> params;

public:
    Request(const std::string & json);

    virtual void print(std::ostream & out) const;
};

}

#endif
