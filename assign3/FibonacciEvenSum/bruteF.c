#include <stdio.h>

long long sumEvenFib(long long n) {
    long long a = 1;
    long long b = 1;
    long long sum = 0;

    while (a <= n) {

        if (a % 2 == 0)
            sum += a;

        long long c = a + b;
        a = b;
        b = c;
    }

    return sum;
}

int main() {
    long long n;

    printf("Enter n: ");
    scanf("%lld", &n);

    printf("%lld\n", sumEvenFib(n));

    return 0;
}
