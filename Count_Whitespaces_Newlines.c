#include <stdio.h>

int main() {
    char ch;
    int spaces = 0, newlines = 0;

    printf("Enter text (press Ctrl+D to end input on Linux/macOS or Ctrl+Z on Windows):\n");

    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\t') {
            spaces++;
        } else if (ch == '\n') {
            newlines++;
        }
    }

    printf("\nNumber of whitespace characters (spaces/tabs): %d\n", spaces);
    printf("Number of newline characters: %d\n", newlines);

    return 0;
}
