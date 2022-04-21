#include "change_name.h"
#include "map.h"
#define MODULO 1000000007U
#define P 53U

static const char *instructions[] = {"ADC", "AND", "ASL", "BBR", "BBS",
									  "BCC", "BCS", "BEQ", "BIT", "BMI",
									  "BNE", "BPL", "BRA", "BRK", "BVC",
									  "BVS", "CLC", "CLD", "CLI", "CLV",
									  "CMP", "CPX", "CPY", "DEC", "DEX",
									  "DEY", "EOR", "INC", "INX", "INY",
									  "JMP", "JSR", "LDA", "LDX", "LDY",
									  "LSR", "NOP", "ORA", "PHA", "PHP",
									  "PHX", "PHY", "PLA", "PLP", "PLX",
									  "PLY", "RMB", "ROL", "ROR", "RTI",
									  "RTS", "SBC", "SEC", "SED", "SEI",
									  "SMB", "STA", "STP", "STX", "STY",
									  "STZ", "TAX", "TAY", "TRB", "TSB",
									  "TSX", "TXA", "TXS", "TYA", "WAI"};

uint32_t hash_function(char *string) {
	uint32_t hash = 0U, poly = 1U;
	while(string != (void*)0 && *string != '\0') {
		hash = (hash + (*string - 'A') * poly)%MODULO;
		poly *= P;
		string++;
	}
	return hash;
}
