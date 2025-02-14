
# Notes: Data Structures in C

In C we're got two built in tools for structuring data:

 - Arrays
 - Structs

This is sufficient to build any data type, but we really do want
to build some more complex data types to get stuff done.

E.g. Sized array:

```C
typedef struct sized_array {
    DATA* data;
    long size;
} sized_array;
```


Most common modern programming languages provide two basic data structures
in their standard library:

 - A dynamically-sized sequence type; most commonly a variable-length Array
   - VLAs include Python List, JS Array, C++ vector, Java ArrayList
 - A key-value map type; most commonly a hash table
   - Hash tables include Python Dict, all JS objects, C++ unordered_map, Java HashMap


## VLA: The Plan

 - Problem: Arrays in C are fixed length, we'd like to be able to add stuff to the
   end of our lists.
 - Basic operation is append to end: ```push_back```, Java calls it "add"
 - With fixed length array, need to allocate whole new array, copy items over, this is O(n)

Solution: Allocate extra space. Specifically, double the array size
every time we need to reallocatate.

That requires a more complex structure:

```C
typedef struct vla {
    T* item;
    long size; // number of items stored in the VLA
    long cap;  // size of allocated array
} vla;
```



## Hash Tables

 - Problem: Want to store a key-value map.
 - Plan A: A list of key-value pairs
 - Problem: All operations would be O(n).


```python
sounds = {"cow": "moo", "dog": "bork"}
sounds = [("cow", "moo"), ("dog", "bork")]
```

Idea: Use a constant time function to map a key to
an array slot.

```C
typedef struct kv_pair {
    K key;
    V val; 
} kv_pair;

typedef struct hash_table {
    kv_pair* data;  // array
    long size;
    long cap;
}
```

If everything goes well, we can get expected O(1) time for common
operations.


