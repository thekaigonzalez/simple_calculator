/*Copyright 2019-2023 Kai D. Gonzalez*/

#ifndef AMA_FN_H
#define AMA_FN_H

#include "ama_n.h"
#include "ama_s.h"

// defines a function that takes in a parameter and returns a number
typedef int (*ama_transf_t) (ama_stack *n);

// runs fn(s->n)
void ama_perform (ama_stack *s, ama_transf_t fn);

#endif
