#include <stdint.h>
#include <stdlib.h>
#define MAX_SYMBOLS 256

typedef struct {
    char *name;
    uint8_t address;
} SymbolEntry;

SymbolEntry symbol_table[MAX_SYMBOLS];
uint8_t current_address = 0x10;  // Start assigning addresses at 0x10

void add_symbol(char *name) {
    symbol_table[current_address - 0x10].name = name;
    symbol_table[current_address - 0x10].address = current_address;
    current_address++;
}

uint8_t get_address(char *name) {
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return symbol_table[i].address;
        }
    }
    return 0;  // Error: variable not found
}