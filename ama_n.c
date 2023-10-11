#include "ama_n.h"

#include <ctype.h>
#include <stdlib.h>

ama_default_number_t
ama_convert_to_number (ama_number *n)
{
  if (n->value == NULL)
    return -1;
  return atof (n->value);
}

ama_number
ama_create_number (char *value)
{
  ama_number n;
  n.value = (value);

  return n;
}
