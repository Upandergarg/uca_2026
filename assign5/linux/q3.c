#include <stdio.h>

int fitsBits(int x, int n) {
	//adding negative with two s compliment , 
	//we want to keep only the bits that are orignal in provided range -> n
    int shift = 32 + (~n + 1);   
    return !((((x << shift) >> shift) ^ x));
}

int main() {
    int x, n;

   
    scanf("%d", &x);

 
    scanf("%d", &n);

    if (fitsBits(x, n))
        printf("%d fits in %d bits.\n", x, n);
    else
        printf("%d does NOT fit in %d bits.\n", x, n);

    return 0;
}
