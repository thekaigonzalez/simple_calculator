#include "ama_s.h"

void
ama_add_to_stack (ama_stack *s, ama_number* n)
{
    s->n[s->incr].value = n->value;
    s->incr++;
}

void
ama_stack_start (ama_stack *s)
{
    s->incr = 0;
    for (int i = 0; i < AMA_STACK_SIZE - 1; i++) {
        s->n[i] = ama_default(); // set number to default
    }
}

ama_number
ama_default ()
{
  return ama_create_number("0");
}

void
ama_push_result (ama_stack *s, ama_default_number_t result)
{
    s->last = result;
}

ama_default_number_t
ama_last_result (ama_stack *s)
{
  return s->last;
}
