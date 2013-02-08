#ifndef MOOGUOR_ADAPATER_MONGO_H
#define MOOGUOR_ADAPATER_MONGO_H

#include <string>
#include "object.h"

namespace Mooguor {
namespace Adapter {

class Mongo: public Adapter {
    Mongo(const std::string & dbc);

    virtual void handleRequest(const Request & req);
};

}
}

#endif
