#include <stdio.h>

int main() {
    char file[100];
    FILE *fp;
    int c, next;

    printf("Enter file name: ");
    scanf("%s", file);

    fp = fopen(file, "r");

    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) {

        // String
        if (c == '"') {
            putchar(c);

            while ((c = fgetc(fp)) != EOF) {
                putchar(c);

                if (c == '\\') {
                    putchar(fgetc(fp));
                }
                else if (c == '"') {
                    break;
                }
            }
        }

        // Character constant
        else if (c == '\'') {
            putchar(c);

            while ((c = fgetc(fp)) != EOF) {
                putchar(c);

                if (c == '\\') {
                    putchar(fgetc(fp));
                }
                else if (c == '\'') {
                    break;
                }
            }
        }

        // Possible comment
        else if (c == '/') {

            next = fgetc(fp);

            if (next == '/') {          // Single-line comment
                while ((c = fgetc(fp)) != '\n' && c != EOF);
                if (c == '\n')
                    putchar('\n');
            }

            else if (next == '*') {     // Multi-line comment
                int prev = 0;

                while ((c = fgetc(fp)) != EOF) {
                    if (prev == '*' && c == '/')
                        break;
                    prev = c;
                }
            }

            else {                      // Not a comment
                putchar(c);
                putchar(next);
            }
        }

        else {
            putchar(c);
        }
    }

    fclose(fp);
    return 0;
}
