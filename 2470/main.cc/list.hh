#ifndef LIST_HH
#define LIST_HH

#include <memory>

// bad style
using namespace std;

// A ConsList is either:
//  - A Cell(head, tail)
//  - Empty

template <typename T>
class ListBase {
public:
    virtual bool is_empty() = 0;
    virtual int length() = 0;
};

template <typename T>
using List = unique_ptr<ListBase<T>>;

template <typename T>
class ListEmpty : public ListBase<T> {
public:
    bool is_empty() { return true; }
    int length() { return 0; }
};

template <typename T>
class ListCell : public ListBase<T> {
public:
    T head;
    List<T> tail;

    bool is_empty() { return false; }
    int length() { return 1 + tail->length(); }
};

template <typename T>
List<T>
cons(T hd, List<T> tl)
{
    return make_unique<ListCell<T>>(hd, tl);
}

template <typename T>
const List<T> empty()
{
    return make_unique<ListEmpty<T>>();
}

#endif
