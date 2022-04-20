/*
 * Header file for Pass 1 of the Two-Pass-Assembler.
 */

#ifndef PASS1
#define PASS1
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct token_list_node {
	char *token;
	struct token_list_node *next;
}Token_Node;

typedef struct node_apis {
	Token_Node* (*create)(char const * string, uint32_t length);
}Node;

Node *AccessNodeAPIs();
char **split_into_tokens(char const * const);

#endif
