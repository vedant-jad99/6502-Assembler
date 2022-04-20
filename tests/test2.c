/*
 * Test to check the creation of Token_Node, a node for linked list of tokens, and it's abstraction.
 */

#include "common.h"
#include "pass1.h"

/*
 * Function to test the creation of and accessing Node and inner APIs. 
 *
 * param: Void pointers.
 * return: True if Token_Node created. False otherwise.
 */

bool test1(void *arg1, void *arg2) {
	Node *testNode = NULL;
	testNode = AccessNodeAPIs();
	if(testNode == NULL) {
		return false;
	}
	Token_Node *testTokenNode = NULL;
	testTokenNode = testNode->create("dummy", 5);
	if(testTokenNode == NULL) {
		return false;
	}
	return true;
}
/*
 * Function to test the creation of Token_Node
 *
 * param: Void pointers.
 * return: True if Token_Node created. False otherwise.
 */

bool test2(void *arg1, void *arg2) {
	char *string = (char *)arg1;
	uint8_t length = *(uint8_t *)arg2;

	Node *NodeInterface = AccessNodeAPIs();
	Token_Node *node = NodeInterface->create(string, length);
	if(node == NULL) {
		return false;
	}
	if(node->token == NULL) {
		return false;
	}	
	uint8_t compare = strcmp(node->token, string);
	if(compare == 0U) {
		return true;
	}
	return false;
}

/*
 * Function to run the tests and check how many test cases pass.
 *
 * param: An array of function pointers
 * 		  Test string
 * 		  Length of string
 * return: Number of test cases passed.
 */
uint8_t run_tests(bool (*func[2])(void *, void *), char *string, uint32_t length) {
	uint8_t result = 0U, value = 0U;
	result += (uint8_t)func[0](NULL, NULL);
	if(result == ++value) {
		printf("Test case %u passed...", value);
		printf(GREEN "OK\n" RESET);
	} 
	else {
	    printf("Test case %u in %s...", value, __func__);
		printf(RED "FAILED\n" RESET);
	}	
	result += (uint8_t)func[1](string, &length);
	if(result == ++value) {
		printf("Test case %u passed...", value);
		printf(GREEN "OK\n" RESET);
	}
	else {
		printf("Test case %u in %s...", value, __func__);
		printf(RED "FAILED\n" RESET);
	}
	return result;
}

int main() {
	bool (*func[2])(void *, void *) = {test1, test2};
	char *string = "dummy";
	uint8_t length = 5U, expected = 2U;
	uint8_t result = run_tests(func, string, length);
	print_test_result(result, expected, __FILE__);
}
