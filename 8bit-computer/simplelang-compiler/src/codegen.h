// src/codegen.h
#ifndef CODEGEN_H
#define CODEGEN_H

#include "parser.h"

void generate_asm(ASTNode *node, FILE *output);

#endif // CODEGEN_H