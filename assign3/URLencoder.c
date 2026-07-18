#include <stdio.h>

void url_encode(char *str, int true_length) {
    int spaces = 0;

    // Count spaces
    for (int i = 0; i < true_length; i++) {
        if (str[i] == ' ')
            spaces++;
    }

    // Calculate new length
    int index = true_length + (spaces * 2);

    // Null terminate
    str[index] = '\0';

    // Traverse backwards
    for (int i = true_length - 1; i >= 0; i--) {

        if (str[i] == ' ') {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index -= 3;
        } else {
            str[index - 1] = str[i];
            index--;
        }
    }
}

int main() {

    char str[200];
    int true_length;
    fgets(str, sizeof(str), stdin);

    printf("Enter the true length: ");
    scanf("%d", &true_length);

    url_encode(str, true_length);

    printf("Encoded String: %s\n", str);

    return 0;
}
