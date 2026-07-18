#include <stdio.h>

void reverse_string(char *str) {
    int length = 0;

    while (str[length] != '\0')
        length++;

    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s \"insufficent arguments\"\n", argv[0]);
        return 1;
    }

    reverse_string(argv[1]);

    printf("%s\n", argv[1]);

    return 0;
}
