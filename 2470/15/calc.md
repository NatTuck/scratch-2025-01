

Input: 2 + 4
Output: 6

Input 3 * 2
Output: 6

Input: - 2 + 4*2
Output: 6

```C
while (1) {
    char* line = read_one_line();
    int yy = eval(line);
    printf("%d\n", yy);
}
```

Steps:

 - Input string.
   - "2 + 4*2"
 - Split expression into tokens.
   - "2" "+" "4" "*" "2"
 - Parse into a tree.
   - (+ 2 (* 4 2))
 - Evaluate the tree
   - 8
