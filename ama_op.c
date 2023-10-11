#include "ama_op.h"
/*Copyright 2019-2023 Kai D. Gonzalez*/
void
ama_init_op (ama_op *op, char t, ama_transf_t fn)
{
    op->token = t;
    op->fn = fn;
}

void
ama_add_to_op_list (ama_operator_list *op_list, ama_op *op)
{
    op_list->ops[op_list->incr] = *op;
    op_list->incr++;
}

void
ama_easy_add_to_op_list (ama_operator_list *op_list, char t, ama_transf_t fn)
{
    ama_init_op (&op_list->ops[op_list->incr], t, fn);
    op_list->incr++;
}

void
ama_start_operator_list (ama_operator_list *op_list)
{
    op_list->incr = 0;
}

void
ama_run_function (ama_stack* s, ama_operator_list *op_list, char t)
{
    for (int i = 0; i < AMA_STACK_SIZE; i++) {
        if (i > op_list->incr) {
            break;
        }
        if (op_list->ops[i].token == t) {
            op_list->ops[i].fn(s);
        }
    }
}

int
ama_validate_operator (ama_operator_list *c, char t)
{
    for (int i = 0; i < AMA_STACK_SIZE; i++) {
        if (i > c->incr) {
            break;
        }
        if (c->ops[i].token == t) {
            return 1;
        }
    }
    return 0;
}
