#include "common.h"
#include "map.h"

uint8_t run_tests(char *strings[], uint32_t *expected_hash_values, uint8_t length) {
	uint8_t result = 0U;
	uint32_t hash = 0U; 
	for(uint8_t i = 0U; i < length; i++) {
		hash = hash_function(strings[i]);
		if(hash == expected_hash_values[i]) {
			result++;
			printf("Test case %u passed...", i);
			printf(GREEN "OK\n" RESET);
		}
		else {
			printf("Test case %u in %s...", i + 1, __func__);
		    printf(RED "FAILED\n" RESET);	
		}
	}
	return result;
}

int main() {
	uint8_t expected = 10U, length = 10U, result = 0U;
	char *strings[10] = {"A", "B", "AB", "CD", "ABCDE", "ADC", "AND", "BCC", "BCS", "LDA"};
	//Tests will fail for some test cases. To pass all, convert 0U to the respective hash value.
	uint32_t expected_hash_values[10] = {0U, 1U, 53U, 161U, 0U, 5777U, 0U, 0U, 0U, 0U};
	result = run_tests(strings, expected_hash_values, length);
	print_test_result(result, expected, __FILE__);
	return 0;
}
