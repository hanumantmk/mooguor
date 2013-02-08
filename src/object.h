#ifndef MOOGUOR_OBJECT_H
#define MOOGUOR_OBJECT_H

#include <ostream>

namespace Mooguor {

class Object {

public:
    virtual ~Object() {};

    virtual void print(std::ostream & stream) const {};
};

};

std::ostream & operator<<(std::ostream & out, const Mooguor::Object & obj);

#endif
