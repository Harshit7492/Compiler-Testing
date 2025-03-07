// src/parser.h
#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

// Define node types
typedef enum {
    NODE_ASSIGN,    // Assignment (e.g., a = b + 10)
    NODE_BINOP,     // Binary operation (e.g., a + b)
    NODE_VAR_DECL,  // Variable declaration (e.g., int a)
    NODE_IF         // Conditional (e.g., if (a == b))
} NodeType;

// Define AST node structure
typedef struct ASTNode {
    NodeType type;  // Node type (e.g., NODE_ASSIGN)
    char *id;       // Variable name (e.g., "a")
    int value;      // Literal value (e.g., 10)
    struct ASTNode *left;   // Left child
    struct ASTNode *right;  // Right child
} ASTNode;

// Function prototypes
ASTNode *parse(FILE *file);

#endif // PARSER_H