#include "list.hh"

#include <iostream>

int main(int argc, char* argv[])
{
    List<int> xs = cons(5, cons(10, cons(20, empty<int>())));
    cout << "xs len: " << xs->length() << endl;

    List<int> ys = cons(50, cons(100, xs->get_tail()));
    cout << "ys len: " << ys->length() << endl;

    cout << "xs len: " << xs->length() << endl;

    List<string> zs = cons("aa", cons("bb", cons("cc", empty<string>())));
    cout << "zs len: " << zs->length() << endl;

    return 0;
}
