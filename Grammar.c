#include <stdio.h>
#include <string.h>

int i = 0;
char input[100];

// Recursive function to simulate S → aSb | ε
int S() {
    if (input[i] == 'a') {
        i++;
        if (S()) {
            if (input[i] == 'b') {
                i++;
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    // ε (empty string is accepted)
    return 1;
}

int main() {
    printf("Enter the string to check: ");
    scanf("%s", input);

    if (S() && input[i] == '\0') {
        printf("The string belongs to the grammar.\n");
    } else {
        printf("The string does NOT belong to the grammar.\n");
    }

    return 0;
}
