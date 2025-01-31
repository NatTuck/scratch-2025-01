#include <stdio.h>


int
all_match(char c, char* text)
{
  for (int ii = 0; text[ii] != 0; ++ii) {
    if (text[ii] != c) {
      return 0;
    }
  }
  return 1;
}

int
main(int argc, char* argv[])
{
  // assume there is one command line argument

  if (all_match('5', argv[1])) {
    puts("yup, all fives");
  }
  else {
    puts("nope");
  }
        
  return 0;
}
