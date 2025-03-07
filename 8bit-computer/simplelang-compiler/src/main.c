// src/main.c
#include <stdio.h>
#include "lexer.h"
#include "parser.h"
#include "codegen.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input.slang>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen("output.asm", "w");

    if (!input || !output) {
        perror("Error opening files");
        return 1;
    }

    // Lex → Parse → CodeGen
    ASTNode *root = parse(input);
    generate_asm(root, output);

    fclose(input);
    fclose(output);
    return 0;
}