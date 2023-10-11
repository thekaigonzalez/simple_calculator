/*Copyright 2019-2023 Kai D. Gonzalez*/

#ifndef STACK_H
#define STACK_H

#include "ama_li.h"
#include "ama_n.h"

#define AMA_DIGIT(x) ((x) >= '0' && (x) <= '9')

typedef struct ama_stack
{
  ama_number n[AMA_STACK_SIZE];
  ama_default_number_t last;
  int incr;
} ama_stack;

void ama_add_to_stack (ama_stack *s, ama_number *n);
void ama_stack_start (ama_stack *s);
ama_number ama_default(); // returns a number thats 0
void ama_push_result(ama_stack *s, ama_default_number_t result);
ama_default_number_t ama_last_result(ama_stack *s);

#endif
