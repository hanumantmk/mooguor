#include <iostream>

#include "variant.hpp"
#include "variant_string.hpp"
#include "variant_list.hpp"
#include "variant_map.hpp"

#include "parser_json.hpp"

using namespace Mooguor;
using namespace std;

int main(int argc, char ** argv)
{
    Variant foo("foo");
    Variant bar(12);

    VariantMap * map = new VariantMap();
    VariantList * list = new VariantList();

    (*map)["string"] = foo;
    (*map)["int"] = bar;

    list->push_back(foo);
    list->push_back(bar);

    Variant vmap(map);
    list->push_back(vmap);

    Variant baz(list);

    cout << baz << endl;
    cout << baz.toList()[1] << endl;

    Parser::JSON jparser;

    cout << jparser.parse("{ \"foo\" : [ \"bar\", 10 ] }") << endl;

    return 0;
}
