
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

typedef struct slice {
    const char* ptr;
    int len;
} slice;

typedef struct scell {
    slice item;
    struct scell* next;
} scell;

scell*
scons(slice item, scell* next)
{
    scell* xs = malloc(sizeof(scell));
    xs->item = item;
    xs->next = next;
    return xs;
}

void
sfree(scell* xs)
{
    if (xs) {
        sfree(xs->next);
        free(xs);
    }
}

int
slength(scell* xs)
{
    if (xs == 0) {
        return 0;
    }
    else {
        return 1 + slength(xs->next);
    }
}

slice
to_slice(const char* text)
{
    slice yy;
    yy.ptr = text;
    yy.len = strlen(text);
    return yy;
}

int
sleq(slice aa, slice bb)
{
    if (aa.len != bb.len) {
        return 0;
    }

    for (int ii = 0; ii < aa.len; ++ii) {
        if (aa.ptr[ii] != bb.ptr[ii]) {
            return 0;
        }
    }

    return 1;
}

long
file_size(const char* path)
{
    struct stat sb;
    int rv = stat(path, &sb);
    assert(rv != -1);

    return sb.st_size;
    // struct stat sb -> struct stat* (pointing to sb)
    //    &sb   (& is address of, giving us the address in memory of a thing)
    // struct stat* sbp -> struct stat (with a copy of the data pointed to)
    //    *sbp  (* is the dereference operator, which follows a pointer)
}

scell*
split_lines(const char* data, long sz)
{
    scell* ys = 0;

    slice item; // ptr, len
    item.ptr = data;

    int cur_len = 0;
    for (long ii = 0; ii < sz; ++ii) {
        if (data[ii] == '\n') {
            item.len = cur_len;
            ys = scons(item, ys);
            item.ptr = &(data[ii + 1]);
            cur_len = 0;
        }
        else {
            cur_len += 1;
        }
    }

    return ys;
}

int
slice_compare(const void* vaa, const void* vbb)
{
    slice* aa = (slice*) vaa;
    slice* bb = (slice*) vbb;

    char st0[aa->len + 1];
    char st1[bb->len + 1];
    memcpy(st0, aa->ptr, aa->len);
    st0[aa->len] = 0;
    memcpy(st1, bb->ptr, bb->len);
    st1[bb->len] = 0;
    return strcmp(st0, st1);
}

scell*
sort_slices(scell* xs)
{
    int nn = slength(xs);
    slice items[nn];

    int ii = 0;
    for (scell* it = xs; it; it = it->next) {
        items[ii++] = it->item;
    }

    qsort(items, nn, sizeof(slice), slice_compare);

    sfree(xs);

    scell* ys = 0;
    for (int ii = nn - 1; ii >= 0; --ii) {
        ys = scons(items[ii], ys);
    }

    return ys;
}
 
int
main(int argc, char* argv[])
{
    assert(argc == 2);

    const char* path = argv[1];

    long sz = file_size(path);
    char* data = malloc(sz);

    FILE* fh = fopen(path, "r");
    int count = 0;
    while (count < sz) {
        int rv = fread(data + count, 1, sz - count, fh);
        assert(rv != 0);
        count += rv;
    }
    fclose(fh);

    scell* lines = split_lines(data, sz);

    lines = sort_slices(lines);

    for (scell* it = lines; it; it = it->next) {
        printf("%.*s\n", it->item.len, it->item.ptr);
    }

    sfree(lines);
    
    free(data);
    return 0;
}
