#include "ama_ca.h"
#include "ama_fn.h"
#include "ama_n.h"
#include "ama_op.h"

main ()
{
  ama_stack s;

  ama_stack_start (&s);

  //   ama_number one = ama_create_number("1");

  //   ama_add_to_stack(&s, &one);
  //   ama_add_to_stack(&s, &one);

  //   ama_perform (&s, sample_add_function);

  ama_evaluate (&s, "12+7+3");
  printf ("%i\n", ama_last_result (&s));
}
