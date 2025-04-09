#ifndef LIST_HH
#define LIST_HH

#include <memory>
#include <stdlib.h>

// bad style
using namespace std;

// A ConsList is either:
//  - A Cell(head, tail)
//  - Empty

template <typename T>
class ListBase;

template <typename T>
using List = shared_ptr<ListBase<T>>;

template <typename T>
class ListBase {
public:
    virtual bool is_empty() = 0;
    virtual int length() = 0;
    virtual List<T> get_tail() = 0;
};

template <typename T>
class ListEmpty : public ListBase<T> {
public:
    bool is_empty() { return true; }
    int length() { return 0; }
    List<T> get_tail() { abort(); }
};

template <typename T>
class ListCell : public ListBase<T> {
public:
    const T head;
    const List<T> tail;

    ListCell(T hd, List<T> tl)
        : head(hd)
        , tail(tl)
    {
    }

    bool is_empty()
    {
        return false;
    }
    int length() { return 1 + tail->length(); }

    List<T> get_tail() { return tail; }
};

template <typename T>
List<T>
cons(T hd, List<T> tl)
{
    return make_shared<ListCell<T>>(hd, tl);
}

List<string> cons(const char* hd, List<string> tl);

template <typename T>
const List<T> empty()
{
    return make_shared<ListEmpty<T>>();
}

#endif
