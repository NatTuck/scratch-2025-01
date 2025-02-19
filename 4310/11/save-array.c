
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

  int fd = open("./array.dat", O_CREAT|O_TRUNC|O_RDWR, 0644);
  aok(fd);

  int rv = ftruncate(fd, size);
  aok(rv);

  int* xs = mmap(0, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
  aok(rv);

  rv = close(fd);
  aok(rv);

  for (int ii = 0; ii < 10; ++ii) {
    xs[ii] = ii * 10;
  }

  rv = munmap(xs, size);
  aok(rv);

  return 0;
}
