#ifndef MOOGUOR_DEBUG_H
#define MOOGUOR_DEBUG_H

#include "object.hpp"
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

namespace Mooguor {
namespace Debug {

template <class T>
std::string join(const T seq, const char * sep, void (* fun)(typename T::const_iterator, std::ostream &))
{
    std::ostringstream oss;

    for (typename T::const_iterator it = seq.begin(), e = seq.end(); it != e;) {
        fun(it, oss);

        if (++it != e) {
            oss << sep;
        }
    }

    return oss.str();
}

template <class T>
std::string joinObjects(const T seq, const char * sep)
{
    return join<T>(seq, sep, [](typename T::const_iterator it, std::ostream & os){
        os << *it;
    });
}

}
}

#endif
