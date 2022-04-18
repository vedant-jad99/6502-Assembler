#ifndef COMMON
#define COMMON

#define GREEN "\x1B[38;5;40m"
#define RED "\x1B[31;5;40m"
#define RESET "\x1B[0m"
#include <stdint.h>
#include <stdio.h>

void print_test_result(uint8_t result, char *file_name);

#endif
