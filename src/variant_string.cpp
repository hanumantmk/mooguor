#include "variant_string.hpp"

using namespace Mooguor;

VariantString::VariantString(const char * c) : s(c) {}
VariantString::VariantString(std::string & s) : s(s) {}

VariantString::VariantString(const VariantString & vs) : s(vs.s) {}
VariantString::VariantString(VariantString && vs)
{
    using std::swap;

    swap(s, vs.s);
}

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
