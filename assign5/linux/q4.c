#include <stdio.h>

int sign(int x) {
	//here !!x will give one for nonzero and zero for zero values
    return (x >> 31) | (!!x);
}

int main() {
    int x;

    printf("Enter a number: ");
    scanf("%d", &x);

    printf("Sign = %d\n",sign(x));

    return 0;
}
