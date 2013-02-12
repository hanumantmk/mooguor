#ifndef MOOGUOR_VARIANT_H
#define MOOGUOR_VARIANT_H

#include "object.h"
#include "variant_base.h"

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

    union {
        VariantBase * vb_ptr;
        int n;
    } u;

public:
    Variant();
    Variant(const Variant & v);
    Variant(const char * s);
    Variant(std::string & s);
    Variant(int x);
    Variant(VariantList & l);
    Variant(VariantMap & m);
    Variant(VariantString & s);
    Variant(VariantList * l);
    Variant(VariantMap * m);
    Variant(VariantString * s);

    Variant & operator= (const Variant & v);

    ~Variant();

    Type getType() const;

    bool isString() const;
    bool isInt() const;
    bool isList() const;
    bool isMap() const;

    VariantString & toString();
    VariantList & toList();
    VariantMap & toMap();

    const VariantString & toString() const;
    const VariantList & toList() const;
    const VariantMap & toMap() const;
    int toInt();

    virtual void print(std::ostream & out) const;

private:
    Variant & copy(const Variant & in);

};

}

#endif
