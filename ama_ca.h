/*Copyright 2019-2023 Kai D. Gonzalez*/

#ifndef AMA_CA_H
#define AMA_CA_H

#include "ama_s.h"
#include "ama_op.h"

// calculates stack and operators
void ama_evaluate (ama_stack *s, char* expression);

// checks if its a token of any nature
int ama_checktoken (char c);

ama_transf_t
simple_add_function (ama_stack *n);

#endif
