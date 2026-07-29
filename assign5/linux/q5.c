
	
#include <stdio.h>

int getByte(int x, int n) {
	//doing & with it, to remove unwntted bits and keep the bits we want 
    return (x >> (n << 3)) & 0xFF;
}

int main() {
    int x, n;

    printf("Enter number in hexadecimal- ");
    scanf("%x", &x);

    printf("Enter byte number 0-3- ");
    scanf("%d", &n);

    printf("Byte %d = 0x%X\n", n, getByte(x, n));

    return 0;
}
