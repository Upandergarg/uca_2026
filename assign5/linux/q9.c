#include <stdio.h>

int isPower2(int x) {
	//handling edge cases like- if it is 0
	//if it is -
	//and then the property
    return !!x & !(x >> 31) & !((x & (x + ~0)));
}

int main() {
    int x;

    printf("Enter a number: ");
    scanf("%d", &x);

    if (isPower2(x))
        printf("%d is a power of 2.\n", x);
    else
        printf("%d is NOT a power of 2.\n", x);

    return 0;
}
