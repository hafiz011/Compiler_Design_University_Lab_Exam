#include <stdio.h>
#include <ctype.h>
#include <string.h>

char keywords[10][10] = { "int", "float", "if", "else", "while", "do", "for", "return", "char", "double" };

int isKeyword(char *str) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    
    char input[100], token[20];
    int i = 0, j = 0;

    printf("Enter a line of code: ");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0') {
        if (isalnum(input[i])) {
            token[j++] = input[i];
        } else {
            if (j != 0) {
                token[j] = '\0';
                j = 0;

                if (isKeyword(token))
                    printf("'%s' is a Keyword\n", token);
                else if (isdigit(token[0]))
                    printf("'%s' is a Number\n", token);
                else
                    printf("'%s' is an Identifier\n", token);
            }

            if (input[i] == ' ' || input[i] == '\n') {
                // ignore whitespace
            } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '=') {
                printf("'%c' is an Operator\n", input[i]);
            } else if (input[i] == '(' || input[i] == ')' || input[i] == '{' || input[i] == '}' || 
                       input[i] == ';' || input[i] == ',') {
                printf("'%c' is a Delimiter\n", input[i]);
            }
        }
        i++;
    }

    return 0;
}
