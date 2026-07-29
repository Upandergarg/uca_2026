#include <stdio.h>

int bitXor(int x, int y) {
    return ~(~(x & ~y) & ~(~x & y));
}

int main() {
    int x, y;

 
    scanf("%d", &x);


    scanf("%d", &y);

    printf("bitXor(%d, %d) = %d\n", x, y, bitXor(x, y));

    return 0;
}
