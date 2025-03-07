// src/parser.c
#include "parser.h"
#include <stdlib.h>  // Add this line for malloc

ASTNode *parse(FILE *file) {
    // Example: Parse a simple assignment (a = 10)
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = NODE_ASSIGN;
    node->id = "a";  // Variable name
    node->value = 10; // Literal value
    node->left = NULL;
    node->right = NULL;
    return node;
}