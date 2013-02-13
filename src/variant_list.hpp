#ifndef MOOGUOR_VARIANT_LIST_H
#define MOOGUOR_VARIANT_LIST_H

#include "variant.hpp"
#include "variant_base.hpp"
#include <vector>

namespace Mooguor {

class VariantList: public VariantBase {
    std::vector<Variant> elements;

public:
    typedef std::vector<Variant>::iterator iterator;
    typedef std::vector<Variant>::const_iterator const_iterator;

    iterator begin();
    const_iterator begin() const;

    iterator end();
    const_iterator end() const;

    VariantList();
    VariantList(const VariantList & vl);
    VariantList(VariantList && vl);

    int size() const;

    void push_back(Variant v);
    void pop_back();
    const Variant & back() const;
    void reserve(size_t amount);

    virtual void print(std::ostream & out) const;

    Variant & operator[] (int i);
};

}

#endif
