#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fibo(int n)
{
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int prev = 0;
    int cur = 1;
    for (int i = 2; i <= n; i++) {
        int next = prev + cur;
        prev = cur;
        cur = next;
    }
    return cur;
}

int main()
{
    char input_n[5];
    fgets(input_n, 5, stdin);
    int n, i;
    n = atoi(input_n);
    for (i = 0; i <= n; i++) {
        printf("F(%d) = %d\n",i, fibo(i));
    }
    return 0;
}
