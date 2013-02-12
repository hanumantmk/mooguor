#include "debug.hpp"
#include "variant_list.hpp"

using namespace Mooguor;

VariantList::iterator VariantList::begin()
{
    return elements.begin();
}

VariantList::const_iterator VariantList::begin() const
{
    return elements.begin();
}

VariantList::iterator VariantList::end()
{
    return elements.end();
}

VariantList::const_iterator VariantList::end() const
{
    return elements.end();
}

VariantList::VariantList(const std::vector<Variant> & e) : elements(e) {}
VariantList::VariantList() {}

int VariantList::size() const
{
    return elements.size();
}

void VariantList::push_back(const Variant & v)
{
    elements.push_back(v);
}

void VariantList::pop_back()
{
    elements.pop_back();
}

const Variant & VariantList::back() const
{
    return elements.back();
}

void VariantList::print(std::ostream & out) const
{
    std::string str = Debug::joinObjects(*this, ", ");

    out << "LIST(" << str << ")";
}

Variant & VariantList::operator[] (int i)
{
    return elements[i];
}
