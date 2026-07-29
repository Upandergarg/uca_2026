#include <stdio.h>

int bang(int x) {
	//+1 for return statemnt
	////we only care about the sign bit just
	///
	///as 0 is same for both positive and negative it will work here
    return ((x | (~x + 1)) >> 31) + 1;
}

int main() {
    int x;

    printf("Enter a number: ");
    scanf("%d", &x);

    printf("bang(%d) = %d\n", x, bang(x));

    return 0;
}
