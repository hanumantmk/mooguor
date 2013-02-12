#include "debug.h"
#include "variant_map.h"

using namespace Mooguor;

VariantMap::iterator VariantMap::begin()
{
    return map.begin();
}

VariantMap::const_iterator VariantMap::begin() const
{
    return map.begin();
}

VariantMap::iterator VariantMap::end()
{
    return map.end();
}

VariantMap::const_iterator VariantMap::end() const
{
    return map.end();
}

VariantMap::VariantMap(const std::map<std::string, Variant> & e) : map(e) {}
VariantMap::VariantMap() {}

int VariantMap::size() const
{
    return map.size();
}

void VariantMap::print(std::ostream & out) const
{
    out <<
        "MAP(" <<
            Debug::join<VariantMap>(*this, ", ", [](VariantMap::const_iterator it, std::ostream & os){
                os << it->first << " : " << it->second;
            }) <<
        ")";
}

Variant & VariantMap::operator[] (const std::string & k)
{
    return map[k];
}

Variant & VariantMap::operator[] (const char * s)
{
    return map[s];
}
