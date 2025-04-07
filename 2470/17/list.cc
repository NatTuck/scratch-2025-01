
#include <memory>
using std::unique_ptr;

#include "list.hh"

int main(int argc, char *argv[]) {
  unique_ptr<List> xs(unique_ptr<List>(new Cell(
      5, unique_ptr<List>(new Cell(3, unique_ptr<List>(new Empty()))))));

  return 0;
}
