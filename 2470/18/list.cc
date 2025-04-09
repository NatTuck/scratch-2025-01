
#include "list.hh"

#include <string>

List<string>
cons(const char* hd, List<string> tl)
{
    return cons(string(hd), tl);
}
