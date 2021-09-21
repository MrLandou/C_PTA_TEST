#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int fib(int n);
void PrintFN(int m, int n);

int main()
{
    int m, n, t;

    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);

    return 0;
}

int fib(int n) {
    //局限性：不能判断50000以后的斐波那契数
    int a[50000] = {0};
        a[1] = 1;
        a[2] = 1;
    if ((n ==1) || (n == 2)) {
        return 1;
    }
    else {
        for (int i = 3; i <= n; i++) {
            a[i] = a[i - 1] + a[i - 2];
        }
        return a[n];
    }
}

void PrintFN(int m, int n) {
    //flag用于判断[m,n]之间是否有斐波那契数，默认0为没有
    int flag = 0;
   for (int i = 1; i <= n; i++) {
        if (fib(i) >= m && fib(i) <= n) {
                flag = 1;
                printf("%d",fib(i));
            if (fib(i+1) <= n) {
                printf(" ");
            }
        }
    }
    if (flag == 0) {
        printf("No Fibonacci number");
    }
}