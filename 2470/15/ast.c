
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"

val_node*
new_val(int val)
{
    val_node* yy = malloc(sizeof(val_node));
    yy->kind = VAL_KIND;
    yy->val = val;
    return yy;
}

op_node*
new_op(char op, node* left, node* right)
{
    op_node* yy = malloc(sizeof(op_node));
    yy->kind = OP_KIND;
    yy->op = op;
    yy->left = left;
    yy->right = right;
    return yy;
}

void
free_node(node* nn)
{
    if (nn->kind == OP_KIND) {
        op_node* op = (op_node*)nn;
        free_node(op->left);
        free_node(op->right);
    }
    free(nn);
}

char*
tree_to_string(node* nn) {
    char buf[100];

    if (nn->kind == OP_KIND) {
        op_node* op = (op_node*)nn;
        char* lt = tree_to_string(op->left);
        char* rt = tree_to_string(op->right);
        snprintf(buf, 100, "(%c %s %s)\n", op->op, lt, rt);
        free(rt);
        free(lt);
    }
    else {
        // val
        val_node* val = (val_node*)nn;
        snprintf(buf, 100, "%d", val->val);
    }
    return strdup(buf);
}
void
print_tree(node* nn)
{
    char* tmp = tree_to_string(nn);
    printf("%s\n", tmp);
    free(tmp);
}

