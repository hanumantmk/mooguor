#include "variant.h"
#include "variant_map.h"
#include "variant_list.h"
#include "variant_string.h"

using namespace Mooguor;

Variant::~Variant()
{
    switch (getType()) {
        case Variant::Type::STRING:
        case Variant::Type::LIST:
        case Variant::Type::MAP:
            delete u.vb_ptr;
            break;
        default:
            break;
    }
}

Variant::Variant(const char * s) : type(Variant::Type::STRING)
{
    u.vb_ptr = new VariantString(s);
}

Variant::Variant() : type(Variant::Type::NONE) {}

Variant::Variant(const Variant & v)
{
    copy(v);
}

Variant & Variant::copy(const Variant & v)
{
    type = v.type;

    switch (type) {
        case Variant::Type::STRING:
            u.vb_ptr = new VariantString(v.toString());
            break;
        case Variant::Type::LIST:
            u.vb_ptr = new VariantList(v.toList());
            break;
        case Variant::Type::MAP:
            u.vb_ptr = new VariantMap(v.toMap());
            break;
        case Variant::Type::INT:
            u.n = v.u.n;
            break;
        default:
            break;
    }

    return *this;
}

Variant::Variant(std::string & s) : type(Variant::Type::STRING)
{
    u.vb_ptr = new VariantString(s);
}

Variant::Variant(int x) : type(Variant::Type::INT)
{
    u.n = x;
}

Variant::Variant(VariantList & l) : type(Variant::Type::LIST)
{
    u.vb_ptr = new VariantList(l);
}

Variant::Variant(VariantMap & m): type(Variant::Type::MAP)
{
    u.vb_ptr = new VariantMap(m);
}

Variant::Type Variant::getType() const
{
    return type;
}

bool Variant::isString() const
{
    return getType() == Variant::Type::STRING;
}

bool Variant::isInt() const
{
    return getType() == Variant::Type::INT;
}

bool Variant::isList() const
{
    return getType() == Variant::Type::LIST;
}

bool Variant::isMap() const
{
    return getType() == Variant::Type::MAP;
}

VariantString & Variant::toString()
{
    return *(static_cast<VariantString *>(u.vb_ptr));
}

const VariantString & Variant::toString() const
{
    return *(static_cast<VariantString *>(u.vb_ptr));
}

VariantList & Variant::toList()
{
    return *(static_cast<VariantList *>(u.vb_ptr));
}

const VariantList & Variant::toList() const
{
    return *(static_cast<VariantList *>(u.vb_ptr));
}

VariantMap & Variant::toMap()
{
    return *(static_cast<VariantMap *>(u.vb_ptr));
}

const VariantMap & Variant::toMap() const
{
    return *(static_cast<VariantMap *>(u.vb_ptr));
}

void Variant::print(std::ostream & out) const
{
    switch (getType()) {
        case Variant::Type::STRING:
        case Variant::Type::LIST:
        case Variant::Type::MAP:
            u.vb_ptr->print(out);
            break;
        case Variant::Type::INT:
            out << u.n;
            break;
        default:
            out << "?";
            break;
    }
}

Variant & Variant::operator= (const Variant & in)
{
    return copy(in);
}
