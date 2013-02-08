#ifndef MOOGUOR_ADAPATER_H
#define MOOGUOR_ADAPATER_H

#include <string>
#include "object.h"

namespace Mooguor {

class Adapater: public Object {
    virtual ~Adapater() {}

    void loop();

    virtual void handleRequest(const Request & req) = 0;
};

}

#endif
