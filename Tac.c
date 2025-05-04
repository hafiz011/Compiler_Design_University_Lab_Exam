#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tempVarCount = 1;

// Function to generate temporary variable names like t1, t2, ...
char* newTemp() {
    static char temp[3];
    sprintf(temp, "t%d", tempVarCount++);
    return temp;
}

// Function to generate TAC from a basic expression
void generateTAC(char expr[]) {
    char lhs[20], rhs[20], op1[10], op2[10], oper, temp[10];
    int i = 0, j = 0, k = 0;

    // Split LHS and RHS
    while (expr[i] != '=' && expr[i] != '\0') {
        lhs[j++] = expr[i++];
    }
    lhs[j] = '\0';
    i++; // Skip '='

    j = 0;
    while (expr[i] != '\0' && expr[i] != '\n') {
        rhs[j++] = expr[i++];
    }
    rhs[j] = '\0';

    // Assume single operator like a+b, b*c, a<b
    j = 0;
    while (rhs[j] != '\0') {
        if (rhs[j] == '+' || rhs[j] == '-' || rhs[j] == '*' || rhs[j] == '/' ||
            rhs[j] == '<' || rhs[j] == '>' || rhs[j] == '=' || rhs[j] == '!') {
            oper = rhs[j];

            // Check for relational operator (==, !=, <=, >=)
            if (rhs[j+1] == '=')
                oper = rhs[j++]; // e.g., ==, <=, etc.

            strncpy(op1, rhs, j);
            op1[j] = '\0';
            strcpy(op2, rhs + j + 1);
            break;
        }
        j++;
    }

    strcpy(temp, newTemp());

    // Generate TAC
    printf("%s = %s %c %s\n", temp, op1, oper, op2);
    printf("%s = %s\n", lhs, temp);
}

int main() {
    char expression[100];

    printf("Enter expression (e.g., a = b + c): ");
    fgets(expression, sizeof(expression), stdin);

    generateTAC(expression);

    return 0;
}
