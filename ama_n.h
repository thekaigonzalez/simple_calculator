/*Copyright 2019-2023 Kai D. Gonzalez*/

#ifndef NUMBER_H
#define NUMBER_H

// the default number type
// converts numbers to this type
typedef int ama_default_number_t;

// essentially allows long numbers
typedef struct ama_number {
    char* value;    /* The value of the number */
} ama_number;

// converts the number value to an actual number
ama_default_number_t ama_convert_to_number(ama_number* n);

// creates a number based on a string
ama_number ama_create_number(char* value);

#endif
