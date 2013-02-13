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
    Parser::JSON jparser;

    cout <<
        jparser.parse(R"({ "foo" : [ "bar", 10 ] })")
    << endl;
    
    return 0;
}
