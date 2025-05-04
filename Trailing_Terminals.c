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
    char trailing[MAX][MAX]; // trailing[i] stores terminals for rules[i]
    int trailCount[MAX] = {0};

    printf("Enter number of productions: ");
    scanf("%d", &n);

    // Read productions
    for (i = 0; i < n; i++) {
        printf("Enter production %d (e.g., E=id|(E)): ", i + 1);
        scanf("%s", rules[i].production);
        rules[i].nonTerminal = rules[i].production[0];
    }

    // Compute trailing symbols
    for (i = 0; i < n; i++) {
        char *prod = strchr(rules[i].production, '=') + 1;  // skip to RHS
        int len = strlen(prod);
        int k = 0;

        while (k < len) {
            int start = k;
            // Go to the end of one production
            while (prod[k] != '|' && prod[k] != '\0') k++;

            // Now prod[start ... k-1] is one production
            int end = k - 1;
            while (end >= start && !isalnum(prod[end]) && !ispunct(prod[end])) end--;

            if (isalnum(prod[end]) || ispunct(prod[end])) {
                trailing[i][trailCount[i]++] = prod[end];
            }

            k++; // skip '|'
        }
    }

    // Print trailing sets
    printf("\nTrailing terminals:\n");
    for (i = 0; i < n; i++) {
        printf("TRAILING(%c): { ", rules[i].nonTerminal);
        for (j = 0; j < trailCount[i]; j++) {
            printf("%c ", trailing[i][j]);
        }
        printf("}\n");
    }

    return 0;
}
