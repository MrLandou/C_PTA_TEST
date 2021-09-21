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
    1�������������ӣ�Ĭ��ֱ�Ӽӵ�sum��,nΪnumber����iʱ����һ������
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
    flag�����ж�[m,n]֮������������Ĭ��0Ϊû������
    int flag=0;
    for (int i = m; i < n; i++) {
        sum������������������Ƿ񵽴����һ�����ӣ��Ӷ��������'+'
        int sum = 1;
        ���жϸ������Ƿ�Ϊ�����������������������
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