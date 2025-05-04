#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

typedef struct {
    char nonTerminal;
    char production[100];
} Rule;

int main() {
    int n, i, j;
    Rule rules[MAX];
    char leading[MAX][MAX]; // leading[i] stores terminals for rules[i]
    int leadCount[MAX] = {0};

    printf("Enter number of productions: ");
    scanf("%d", &n);

    // Read productions
    for (i = 0; i < n; i++) {
        printf("Enter production %d (e.g., E=id|(E)): ", i + 1);
        scanf("%s", rules[i].production);
        rules[i].nonTerminal = rules[i].production[0];
    }

    // Compute leading symbols
    for (i = 0; i < n; i++) {
        char *prod = strchr(rules[i].production, '=') + 1;  // skip to RHS

        while (*prod != '\0') {
            if (*prod == '|') {
                prod++;
                continue;
            }

            if (islower(*prod) || ispunct(*prod)) { // terminal
                leading[i][leadCount[i]++] = *prod;
            } else {
                // Could add recursive lookup for non-terminals here
            }

            // Skip current production
            while (*prod != '\0' && *prod != '|') prod++;
        }
    }

    // Print leading sets
    printf("\nLeading terminals:\n");
    for (i = 0; i < n; i++) {
        printf("LEADING(%c): { ", rules[i].nonTerminal);
        for (j = 0; j < leadCount[i]; j++) {
            printf("%c ", leading[i][j]);
        }
        printf("}\n");
    }

    return 0;
}
