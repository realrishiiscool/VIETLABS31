#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_KEYWORDS 10
#define MAX_TOKEN_SIZE 100
// List of keywords
const char *keywords[MAX_KEYWORDS] = {
    "int", "float", "if", "else", "while", "return", "void", "main", "char", "double"
};
// Function to check if a string is a keyword
int isKeyword(const char *str) {
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
// Function to identify token type
void identifyToken(const char *token) {
    if (isKeyword(token)) {
        printf("%s is a keyword\n", token);
    } else if (isalpha(token[0]) || token[0] == '_') {
        printf("%s is an identifier\n", token);
    } else if (isdigit(token[0])) {
        printf("%s is a constant\n", token);
    } else if (ispunct(token[0])) {
        printf("%s is an operator or special symbol\n", token);
    } else {
        printf("%s is an unknown token\n", token);
    }
}

int main() {
    char input[256];
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    
    // Removing the newline character from the input if present
    input[strcspn(input, "\n")] = '\0';
    
    char token[MAX_TOKEN_SIZE];
    int tokenIndex = 0;
    
    for (int i = 0; i < strlen(input); i++) {
        char ch = input[i];
        
        if (isspace(ch) || ispunct(ch)) {
            if (tokenIndex != 0) {
                token[tokenIndex] = '\0';
                identifyToken(token);
                tokenIndex = 0;
            }
            if (ispunct(ch)) {
                token[tokenIndex++] = ch;
                token[tokenIndex] = '\0';
                identifyToken(token);
                tokenIndex = 0;
            }
        } else {
            token[tokenIndex++] = ch;
        }
    }
    if (tokenIndex != 0) {
        token[tokenIndex] = '\0';
        identifyToken(token);
    }

    return 0;
}
