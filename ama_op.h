/*Copyright 2019-2023 Kai D. Gonzalez*/

#ifndef OPERATOR_H
#define OPERATOR_H

#include "ama_fn.h"

// extensible operator interface
typedef struct ama_op
{
  char token;      // the operator token (e.g. '+')
  ama_transf_t fn; // the function to run
} ama_op;

typedef struct ama_operator_list
{
  ama_op ops[AMA_STACK_SIZE];
  int incr;
} ama_operator_list;

void ama_init_op (ama_op *op, char t, ama_transf_t fn);
void ama_add_to_op_list (ama_operator_list *op_list, ama_op *op);
void ama_easy_add_to_op_list (ama_operator_list *op_list, char t,
                              ama_transf_t fn);
void ama_start_operator_list (ama_operator_list *op_list);
void ama_run_function (ama_stack *s, ama_operator_list *op_list, char t);
int ama_validate_operator (ama_operator_list *c, char t);

#endif
