#include "ama_fn.h"

#include "ama_ca.h"
#include "ama_n.h"
#include "ama_op.h"

void
ama_perform (ama_stack *s, ama_transf_t fn)
{
  fn (s);
}
