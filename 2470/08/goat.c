
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct goat {
  char *name;
  float horn_length; // in mm
} goat;

goat
make_goat(const char* name)
{
  goat billy;
  billy.name = strdup(name);
  billy.horn_length = 12.0;
  return billy;
}

void
free_goat(goat gg)
{
  free(gg.name);
}

int
main(int argc, char* argv[])
{
  goat xs[2];
  char buf[256];

  for (int ii = 0; ii < 1; ++ii) {
    printf("Enter a goat name:\n");
    fgets(buf, 256, stdin);
    xs[ii] = make_goat(buf);
  }

  xs[1] = make_goat("Steve");

  for (int ii = 0; ii < 2; ++ii) {
    printf("goat name: %s\n", xs[ii].name);
    free_goat(xs[ii]);
  }
  return 0;
}
