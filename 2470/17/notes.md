
# Introducing C++

New features:

- Classes
- Generics, in the form of templates
- A larger standard library, including some common data structures.

## Generics

```C
struct int_cell {
  int head;
  cell* tail;
};

struct long_cell {
  long head;
  cell* tail;
};
```

```C++
template <typename T>
struct cell {
  T head;
  cell<T>* tail;
};

template <typename T>
cell<T>*
cons(T hd, cell<T>* tl)
{
  // FIXME
}

cell<int>* xs = cons(5, cons(4, 0)); // [5, 4]
auto ys = cons(5L, cons(4L, 0)); // [5, 4], with T = long
```

## Classes

```C++
template <typename T>
class Cell<T> {
public:
  T head;
  Cell<T>* tail;

  Cell(T hd, Cell<T>* tl)
  {
    this.head = hd;
    this.tail = tl;
  }

  ~Cell()
  {
    if (this.tail) {
      delete this.tail;
    }
  }

  int length()
  {
    if (tail) {
      return 1 + tail.length();
    }
    else {
      return 1;
    }
  }
};

auto xs = new Cell(5, new Cell(3, new Cell(7, 0)));

delete xs;
```

## A Comprehensive Standard Library

A better string type:

- std::string

Common data structures:

- std::vector (like Java ArrayList)
- std::deque
- std::map (like Java TreeMap)
- std::unordered_map (like JavaHashmap)

Algorithms:

- std::sort
- std::stable_sort
- std::binary_search
- std::next_permutation

Memory:

- std::unique_ptr
- std::shared_ptr

## Why not C++?

C++ is great. Cmake is awful.


## Examples

```C++
using std::string;

int
main()
{
  string hello("hello");
  return 0;
}

```




