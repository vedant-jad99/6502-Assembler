/*
 * Source file of Pass 1 of the Two-Pass-Assembler.
 */

#include "pass1.h"
#define SEP ' '

/*
 * Private function to create a node for linked list of tokens.
 */
static Token_Node *create_node(char const *string, uint32_t n) {
	Token_Node *node = malloc(sizeof(Token_Node));
	if(node != NULL) {
		node->next = NULL;
		node->token = malloc(n + 1);
		if(node->token != NULL) {
			strncpy(node->token, string, n);
			node->token[n] = '\0';
		}
	}
	return node;
}

/*
 * An interface to access private functions for the nodes of linked list.
 * Currently only has access to create function. To be modified later.
 */
Node *AccessNodeAPIs() {
	Node *tokenNodeInterface = malloc(sizeof(Node));
	tokenNodeInterface->create = create_node;
	return tokenNodeInterface;
}

/*
 * Function to be completed. First testing the functions above.
 *
 * 
char **split_into_tokens(char const *const string) {
	char **tokens; 
	uint8_t i = 0U, j = 0U;
	while(string[i] != '\0') {
		if(string[i] == SEP) {
			
		}
	}
	return tokens;
}*/
