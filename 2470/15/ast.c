
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

node*
parse_range(vec* toks, int i0, int i1)
{
    if (i1 - i0 < 1) {
        return (node*) new_val(0);
    }

    if (i1 - i0 == 1) {
        return (node*) new_val(atoi(toks->data[i0]));
    }

    int op_ii = 0;
    char op = ' ';
    for (int ii = i0; ii < i1; ++ii) {
        char cc =toks->data[ii][0];
        if (!isdigit(cc))  {
            // it's an operator
            if (cc == '+' || cc == '-') {
                op = cc;
                op_ii = ii;
            }
            if (cc == '*' || cc == '/') {
                if (op != '+' && op != '-') {
                    op = cc;
                    op_ii = ii;
                }
            }
        }
    }

    //printf("split at %c, ii = %d\n", op, op_ii);
    node* left = parse_range(toks, i0, op_ii);
    node* right = parse_range(toks, op_ii + 1, i1);
    return (node*) new_op(op, left, right);
}

node*
parse(vec* toks)
{
    return parse_range(toks, 0, toks->size);
}

int
apply_op(char op, int xx, int yy)
{
    switch (op) {
    case '+':
        return xx + yy;
    case '-':
        return xx - yy;
    case '*':
        return xx * yy;
    case '/':
        return xx / yy;
    default:
        abort();
    }
}

int
eval(node* nn)
{
    if (nn->kind == VAL_KIND) {
        val_node* vn = (val_node*) nn;
        return vn->val;
    }
    else {
        op_node* opn = (op_node*) nn;
        int lv = eval(opn->left);
        int rv = eval(opn->right);
        return apply_op(opn->op, lv, rv);
    }
}
