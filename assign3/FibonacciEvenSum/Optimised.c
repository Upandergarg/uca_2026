#include <stdio.h>

long long sumEvenFib(long long n) {

    if (n < 2)
        return 0;

    long long sum = 0;

    long long a = 2;   // First even Fibonacci
    long long b = 8;   // Second even Fibonacci

    while (a <= n) {
        sum += a;

        long long c = 4 * b + a;   // Next even Fibonacci
        a = b;
        b = c;
    }

    return sum;
}

int main() {

    long long n;

    printf("Enter n: ");
    scanf("%lld", &n);

    printf("Sum of even Fibonacci numbers = %lld\n", sumEvenFib(n));

    return 0;
}
