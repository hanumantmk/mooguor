#include "object.h"

std::ostream & operator<<(std::ostream & out, const Mooguor::Object & obj) {
    obj.print(out);

    return out;
}
