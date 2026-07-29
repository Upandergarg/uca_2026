#include <stdio.h>

int conditional(int x, int y, int z) {
	//here we going 0 if x is 0 or 1 or x is not 0,
	//making a mask , uisng+1 for soemting like 2s complement handling -1
    int mask = ~(!!x) + 1;
    return (mask & y) | (~mask & z);
}

int main() {
    int x, y, z;

    printf("Enter x, y, z: ");
    scanf("%d %d %d", &x, &y, &z);

    printf("Result = %d\n", conditional(x, y, z));

    return 0;
}
