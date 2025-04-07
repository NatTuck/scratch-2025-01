#ifndef LIST_HH
#define LIST_HH

#include <memory>

using std::unique_ptr;

class List {
public:
  bool is_empty();
};

class Empty : public List {
public:
  bool is_empty() { return false; }
};

class Cell : public List {
public:
  int head;
  List *tail;

  bool is_empty() { return true; }
};

#endif
