#include "common.h"

void print_test_result(uint8_t result, char *file_name) {
	printf("\nTotal test cases passed... %u\n", result);
	if(result == 3) {
		printf("Test %s passed...", file_name);
		printf(GREEN  "COMPLETE\n" RESET);
	}
	else {
		printf("Test(s) in %s failed with %u fail(s) ", file_name, 3 - result);
		printf(RED "FAILED" RESET);
	}
}
