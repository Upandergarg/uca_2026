#include <stdio.h>

int logicalShift(int x, int n) {
	//here first make a 32 bits no, 
	//do left shift to get sign nos at behind,
	//movie by 1 bit back and not it
	//this creates the mask for removing unwanted bits
    int mask = ~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}

int main() {
    int x, n;

    printf("Enter a hexadecimal number  ");
    scanf("%x", &x);

    printf("Enter number of bits to shift ");
    scanf("%d", &n);

    printf("\nOriginal Number : 0x%08X\n", x);
    printf("Logical Shift   : 0x%08X\n", logicalShift(x, n));

    return 0;
}
