#ifndef MOOGUOR_VARIANT_STRING_H
#define MOOGUOR_VARIANT_STRING_H

#include "variant_base.hpp"
#include <string>

namespace Mooguor {

class VariantString: public VariantBase {
private:
    std::string s;

public:
    VariantString(const char * x);
    VariantString(std::string & s);

    VariantString(const VariantString & vs);
    VariantString(VariantString && vs);

    const std::string & toString() const;
    const char * toCString() const;

    virtual void print(std::ostream & out) const;
};

}

#endif
