#include <iostream>

#include "variant.h"
#include "variant_string.h"
#include "variant_list.h"
#include "variant_map.h"

using namespace Mooguor;
using namespace std;

int main(int argc, char ** argv)
{
    Variant foo("foo");
    Variant bar(12);

    VariantMap map;
    VariantList list;

    map["string"] = foo;
    map["int"] = bar;

    list.push_back(foo);
    list.push_back(bar);

    Variant vmap(map);
    list.push_back(vmap);

    Variant baz(list);

    cout << baz << endl;
    cout << baz.toList()[1] << endl;

    return 0;
}
