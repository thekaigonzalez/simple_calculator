#include "ama_ca.h"

#include "string.h"

#include <ctype.h>

ama_transf_t
simple_add_function (ama_stack *n)
{
    ama_default_number_t res = 0;

    for (int i = 0; i < n->incr; i++)
      {
        res = res + ama_convert_to_number(&n->n[i]);
      }

  ama_push_result (n, res);
  return (0);
}

/*Copyright 2019-2023 Kai D. Gonzalez*/
void
ama_evaluate (ama_stack *s, char *expression)
{
  int i = 0;
  int depth = 0; // how far into the expression we are
  char _c = expression[i];
  string str;
  string1 (&str);

  ama_operator_list op_list;
  ama_operator_list op_call_stack;

  ama_start_operator_list (&op_list);
  ama_start_operator_list (&op_call_stack);

  ama_easy_add_to_op_list (&op_list, '+', simple_add_function);

  while ((_c = expression[i]) != '\0')
    {
      if (isdigit (_c))
        {
          string_append (&str, _c);
          //   if (AMA_DIGIT(expression[i + 1])) {
          //     string_append(&str, expression[i + 1]);
          //   }
        }
      else if (ama_checktoken (_c))
        {
          if (depth == 0) // if this is a first-evaluated expression (e.g.
                          // 1+2+3, 1+2 is the first expression)
            {
              //   ama_run_function (s, &op_list, _c);
              ama_number n = ama_create_number (str._p);

              ama_add_to_stack (s, &n); // adds the number to the stack

              string1 (&str);
            }
        }

      i++;
    }

  // post evaluation
  if (str._s != 0)
    {
      ama_number n = ama_create_number (str._p);

      ama_add_to_stack (s, &n); // adds the number to the stack
    }

  ama_run_function (s, &op_list, '+');
}

int
ama_checktoken (char c)
{

  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
