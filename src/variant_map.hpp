#ifndef MOOGUOR_VARIANT_MAP_H
#define MOOGUOR_VARIANT_MAP_H

#include "variant.hpp"
#include "variant_base.hpp"
#include <map>

namespace Mooguor {

class VariantMap: public VariantBase {
    std::map<std::string, Variant> map;

public:
    typedef std::map<std::string, Variant>::iterator iterator;
    typedef std::map<std::string, Variant>::const_iterator const_iterator;

    iterator begin();
    const_iterator begin() const;

    iterator end();
    const_iterator end() const;

    VariantMap();
    VariantMap(const std::map<std::string, Variant> & e);

    int size() const;

    virtual void print(std::ostream & out) const;

    Variant & operator[] (const std::string & k);
    Variant & operator[] (const char * s);
};

}

#endif
