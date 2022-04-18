/*
 * Test to check if header files in include folder are accessed  and ISA enum access.
 */
 
#include "change_name.h"
#include "common.h"

/*
 * Tests to check the enum value.
 * 
 * param: None
 * return: 1 if the value returned is correct
 *
 * Note: Test 3 is designed to fail. To correct it, replace 35 with 36.
 */
uint8_t enum_access1() {
	uint8_t val = ADC; 
	if(val == 0U) {
		return 1U;
	}
	return 0U;
}

uint8_t enum_access2() {
	uint8_t val = CMP;
	if(val == 20U) {
		return 1U;
	}
	return 0U;
}

uint8_t enum_access3() {
	uint8_t val = NOP;
	if(val == 35U) {
		return 1U;
	}
	return 0U;
}

/*
 * Runs the test cases.
 *
 * param: An array of function pointers. 
 * return: Number of test cases passed
 *
 * Note: Can be replaced by a more generic function/header
 */
uint8_t run_tests(uint8_t (*func[3U]) ()) {
	uint8_t counter = 0U, val = 0U;
	for(uint8_t i = 0; i < 3U; i++) {
		val = (*func[i])();
		if(val  == 1U) {
			printf("Test case %u passed...", i);
			printf(GREEN "OK\n" RESET);
			counter += 1;
		}
		else {
			printf("Test case %u in %s...", i, __func__);
		    printf(RED "FAILED\n" RESET);	
		}
	}
	return counter;
}


int main() {
	uint8_t (*func[3])() = {enum_access1, enum_access2, enum_access3};
	uint8_t result = run_tests(func);
	print_test_result(result, __FILE__);
	return 0;
}
