#ifndef MOOGUOR_VARIANT_H
#define MOOGUOR_VARIANT_H

#include <memory>
#include "object.hpp"
#include "variant_base.hpp"

namespace Mooguor {

class VariantString;
class VariantList;
class VariantMap;

class Variant: public VariantBase {
public:
    enum Type {
        NONE,
        STRING,
        INT,
        LIST,
        MAP,
    };

private:
    Type type;

    std::unique_ptr<VariantBase> vb_ptr;

    union {
        int n;
    } u;

public:
    Variant();
    Variant(const Variant & v);
    Variant(Variant && v);
    Variant(const char * s);
    Variant(std::string & s);
    Variant(int x);
    Variant(VariantList l);
    Variant(VariantMap m);
    Variant(VariantString s);

    Variant & operator= (Variant v);

    Type getType() const;

    bool isString() const;
    bool isInt() const;
    bool isList() const;
    bool isMap() const;

    VariantString toString();
    VariantList toList();
    VariantMap toMap();

    const VariantString & toString() const;
    const VariantList & toList() const;
    const VariantMap & toMap() const;
    int toInt();

    virtual void print(std::ostream & out) const;

    void swap(Variant & rhs);

private:
    Variant & copy(const Variant & in);

};

}

#endif
