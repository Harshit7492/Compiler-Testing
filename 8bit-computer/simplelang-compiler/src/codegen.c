// src/codegen.c
#include "codegen.h"

void generate_asm(ASTNode *node, FILE *output) {
    if (!node || !output) return;

    switch (node->type) {
        case NODE_ASSIGN:
            // Example: a = b + 10
            fprintf(output, "lda A, %d\n", node->value);  // Load value into A
            fprintf(output, "sta A, %s\n", node->id);     // Store A into variable
            break;
        case NODE_BINOP:
            // Example: a + b
            fprintf(output, "lda A, %s\n", node->left->id);  // Load left operand
            fprintf(output, "add A, %s\n", node->right->id); // Add right operand
            break;
        case NODE_VAR_DECL:
            // Example: int a
            fprintf(output, "; Variable declaration: %s\n", node->id);
            break;
        case NODE_IF:
            // Example: if (a == b)
            fprintf(output, "lda A, %s\n", node->left->id);  // Load left operand
            fprintf(output, "cmp A, %s\n", node->right->id); // Compare with right operand
            fprintf(output, "jnz end_if\n");                // Jump if not equal
            // Generate code for the if body
            generate_asm(node->left, output);
            fprintf(output, "end_if:\n");
            break;
        default:
            fprintf(stderr, "Unknown node type: %d\n", node->type);
            break;
    }
}