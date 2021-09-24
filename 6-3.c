#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>

int factorsum(int number);
void PrintPN(int m, int n);

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if (factorsum(m) == m) printf("%d is a perfect number\n", m);
    if (factorsum(n) == n) printf("%d is a perfect number\n", n);
    PrintPN(m, n);

    return 0;
}

int factorsum(int number) {
    1是所有数字因子，默认直接加到sum里,n为number整除i时的另一个因子
    int sum=1;
    int n;
    for (int i = 2; i < sqrt(number); i++) {
        if (number % i == 0) {
             n = number / i;
            sum += i+n;
        }
    }
    return sum;
}
void PrintPN(int m, int n) {
    flag用来判断[m,n]之间有无完数，默认0为没有完数
    int flag=0;
    for (int i = m; i < n; i++) {
        sum用来计算输出的因子是否到达最后一个因子，从而无需输出'+'
        int sum = 1;
        先判断该数字是非为完数，如果是在求它的因子
        if (factorsum(i)==i) {
            flag = 1;
            printf("%d = 1 +",i);
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    printf(" %d", j);
                    sum += j;
                    if (sum != factorsum(i)) {
                        printf(" +");
                    }
                }
                
            }
            printf("\n");
        }
    }
    if (flag == 0) {
        printf("No perfect number");
    } 
}
