

# malloc is implemented using mmap

Malloc almost works like this:

```C
static malloc_metadata* mm = 0;

void*
malloc(long size)
{
    if (mm == 0) {
        // we obvoiusly can't do this:
       mm = malloc(sizeof(malloc_metadata*)); 
    }

    size += sizeof(long);
    long* ptr = mmap(0, size, READ|WRITE, MAP_ANONYMOUS, -1, 0);
    *ptr = size;
    return ptr + 1;
}
```

problem 1:

```C
void
free(void* addr)
{
    long* ptr = addr;
    ptr--;
    munmap(ptr, *ptr);
}
```


Problem 2:

```C
for (int ii = 0; ii < 100; ++ii) {
    xs[ii] = malloc(sizeof(int));
}
```
