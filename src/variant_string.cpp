#include "variant_string.hpp"

using namespace Mooguor;

VariantString::VariantString(const char * c) : s(c) {}
VariantString::VariantString(std::string & s) : s(s) {}

const std::string & VariantString::toString() const
{
    return s;
}

const char * VariantString::toCString() const
{
    return s.c_str();
}

void VariantString::print(std::ostream & out) const
{
    out << "STRING(" << s << ")";
}
