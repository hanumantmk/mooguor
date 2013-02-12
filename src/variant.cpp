#include "debug.hpp"
#include "variant.hpp"
#include "variant_map.hpp"
#include "variant_list.hpp"
#include "variant_string.hpp"

using namespace Mooguor;

//Variant::~Variant()
//{
//    switch (getType()) {
//        case Variant::Type::STRING:
//        case Variant::Type::LIST:
//        case Variant::Type::MAP:
//            delete vb_ptr;
//            break;
//        default:
//            break;
//    }
//}

Variant::Variant(const char * s) : type(Variant::Type::STRING)
{
    vb_ptr = std::unique_ptr<VariantBase>(new VariantString(s));
}

Variant::Variant() : type(Variant::Type::NONE) {}

Variant::Variant(const Variant & v)
{
    copy(v);
}

Variant & Variant::copy(const Variant & v)
{
    std::cout << "copy called" << std::endl;
    type = v.type;

    switch (type) {
        case Variant::Type::STRING:
            vb_ptr = std::unique_ptr<VariantBase>(new VariantString(v.toString()));
            break;
        case Variant::Type::LIST:
            vb_ptr = std::unique_ptr<VariantBase>(new VariantList(v.toList()));
            break;
        case Variant::Type::MAP:
            vb_ptr = std::unique_ptr<VariantBase>(new VariantMap(v.toMap()));
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
    vb_ptr = std::unique_ptr<VariantBase>(new VariantString(s));
}

Variant::Variant(int x) : type(Variant::Type::INT)
{
    u.n = x;
}

Variant::Variant(VariantString & s) : type(Variant::Type::STRING)
{
    vb_ptr = std::unique_ptr<VariantBase>(new VariantString(s));
}

Variant::Variant(VariantList & l) : type(Variant::Type::LIST)
{
    vb_ptr = std::unique_ptr<VariantBase>(new VariantList(l));
}

Variant::Variant(VariantMap & m): type(Variant::Type::MAP)
{
    vb_ptr = std::unique_ptr<VariantBase>(new VariantMap(m));
}

Variant::Variant(VariantString * s) : type(Variant::Type::STRING)
{
    vb_ptr = std::unique_ptr<VariantBase>(s);
}

Variant::Variant(VariantList * l) : type(Variant::Type::LIST)
{
    vb_ptr = std::unique_ptr<VariantBase>(l);
}

Variant::Variant(VariantMap * m): type(Variant::Type::MAP)
{
    vb_ptr = std::unique_ptr<VariantBase>(m);
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
    return *(static_cast<VariantString *>(vb_ptr.get()));
}

const VariantString & Variant::toString() const
{
    return *(static_cast<VariantString *>(vb_ptr.get()));
}

VariantList & Variant::toList()
{
    return *(static_cast<VariantList *>(vb_ptr.get()));
}

const VariantList & Variant::toList() const
{
    return *(static_cast<VariantList *>(vb_ptr.get()));
}

VariantMap & Variant::toMap()
{
    return *(static_cast<VariantMap *>(vb_ptr.get()));
}

const VariantMap & Variant::toMap() const
{
    return *(static_cast<VariantMap *>(vb_ptr.get()));
}

void Variant::print(std::ostream & out) const
{
    switch (getType()) {
        case Variant::Type::STRING:
        case Variant::Type::LIST:
        case Variant::Type::MAP:
            vb_ptr->print(out);
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
