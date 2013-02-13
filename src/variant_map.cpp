#include "debug.hpp"
#include "variant_map.hpp"

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

VariantMap::VariantMap() {}
VariantMap::VariantMap(const VariantMap & vm) : map(vm.map) {}
VariantMap::VariantMap(VariantMap && vm)
{
    using std::swap;

    swap(map, vm.map);
}

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
