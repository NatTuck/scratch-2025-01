
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>

void
assert_okay(long rv, int line)
{
  if (rv == -1) {
    fprintf(stderr, "at line %d, ", line);
    perror("syscall failed");
  }
}

#define aok(rv) assert_okay((long) rv, __LINE__)

int
main(int argc, char* argv[])
{
  long size = 10 * sizeof(int);

  int fd = open("./array.dat", 0);
  aok(fd);

  int* xs = mmap(0, size, PROT_READ, MAP_SHARED, fd, 0);
  aok(xs);

  int rv = close(fd);
  aok(rv);

  for (int ii = 0; ii < 10; ++ii) {
    printf("%d: %d\n", ii, xs[ii]);
  }

  rv = munmap(xs, size);
  aok(rv);

  return 0;
}
