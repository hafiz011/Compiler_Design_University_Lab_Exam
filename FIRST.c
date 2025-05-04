#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 10

char productions[MAX][10];
char first[MAX][10];
int numProductions;

// Function declarations
void findFirst(char, int, int);
int isTerminal(char);

int main() {
    int i;
    char nonTerminal;

    printf("Enter number of productions: ");
    scanf("%d", &numProductions);

    printf("Enter productions (e.g., E=TR):\n");
    for (i = 0; i < numProductions; i++) {
        scanf("%s", productions[i]);
    }

    for (i = 0; i < numProductions; i++) {
        nonTerminal = productions[i][0];
        printf("FIRST(%c) = { ", nonTerminal);
        findFirst(nonTerminal, 0, 0);
        for (int j = 0; first[i][j] != '\0'; j++) {
            printf("%c ", first[i][j]);
        }
        printf("}\n");
    }

    return 0;
}

// Check if symbol is terminal
int isTerminal(char symbol) {
    return !isupper(symbol);
}

// Recursive FIRST function
void findFirst(char symbol, int row, int col) {
    int i, j;
    if (isTerminal(symbol)) {
        first[row][col] = symbol;
        first[row][col + 1] = '\0';
        return;
    }

    for (i = 0; i < numProductions; i++) {
        if (productions[i][0] == symbol) {
            if (isTerminal(productions[i][2]) || productions[i][2] == '#') {
                // Direct terminal or epsilon
                first[row][col++] = productions[i][2];
            } else {
                // Recursive call for non-terminal
                findFirst(productions[i][2], row, col);
            }
        }
    }

    // Remove duplicates
    for (i = 0; i < strlen(first[row]); i++) {
        for (j = i + 1; j < strlen(first[row]); ) {
            if (first[row][i] == first[row][j]) {
                for (int k = j; k < strlen(first[row]); k++) {
                    first[row][k] = first[row][k + 1];
                }
            } else {
                j++;
            }
        }
    }
}
