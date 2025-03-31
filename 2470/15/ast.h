#ifndef AST_H
#define AST_H

typedef struct node {
    int kind;
} node;

typedef struct val_node {
    int kind;
    int val;
} val_node;

typedef struct op_node {
    int kind;
    char op;
    node* left;
    node* right;
} op_node;

#define VAL_KIND 10
#define OP_KIND 11

val_node* new_val(int val);
op_node* new_op(char op, node* left, node* right);
void free_node(node* node);
void print_tree(node* node);

#endif
