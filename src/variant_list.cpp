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

VariantList::VariantList() {}
VariantList::VariantList(const VariantList & vl) : elements(vl.elements) {}
VariantList::VariantList(VariantList && vl)
{
    using std::swap;

    swap(elements, vl.elements);
}

int VariantList::size() const
{
    return elements.size();
}

void VariantList::push_back(Variant v)
{
    using std::swap;

    elements.push_back(std::move(v));
}

void VariantList::pop_back()
{
    elements.pop_back();
}

void VariantList::reserve(size_t amount)
{
    elements.reserve(amount);
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
