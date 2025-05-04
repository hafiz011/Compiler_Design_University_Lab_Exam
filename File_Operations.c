#include <stdio.h>
#include <stdlib.h>

void writeToFile();
void readFromFile();
void appendToFile();

int main() {
    int choice;

    while (1) {
        printf("\nFile Operations Menu:\n");
        printf("1. Write to File\n2. Read from File\n3. Append to File\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
        case 1:
            writeToFile();
            break;
        case 2:
            readFromFile();
            break;
        case 3:
            appendToFile();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void writeToFile() {
    FILE *fp;
    char filename[100], content[1000];

    printf("Enter file name to create/write: ");
    scanf("%s", filename);
    getchar();  // Clear input buffer

    printf("Enter content to write:\n");
    fgets(content, sizeof(content), stdin);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }

    fputs(content, fp);
    fclose(fp);
    printf("Content written to %s successfully.\n", filename);
}

void readFromFile() {
    FILE *fp;
    char filename[100], ch;

    printf("Enter file name to read: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("Content of %s:\n", filename);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
}

void appendToFile() {
    FILE *fp;
    char filename[100], content[1000];

    printf("Enter file name to append: ");
    scanf("%s", filename);
    getchar();  // Clear input buffer

    printf("Enter content to append:\n");
    fgets(content, sizeof(content), stdin);

    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file for appending!\n");
        return;
    }

    fputs(content, fp);
    fclose(fp);
    printf("Content appended to %s successfully.\n", filename);
}
