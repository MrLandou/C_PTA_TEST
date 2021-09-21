#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

double funcos(double e, double x);

int main() {
	double e, x;

	scanf("%lf %lf",&e,&x);
	printf("cos(%.2f) = %.6f\n",x,funcos(e,x));
	return 0;
}
double funcos(double e, double x) {
	double a = 1;
	int b = 1;
	int k = 1;
	int i = 0;
	//第一项直接放入sum中,c为项数值
	double sum=1;
	double c = a / b;
	while (c>e) {
		a *= pow(x, 2);
		b =b*(i+1)*(i+2);
		c =a/b;
		sum = sum + c * pow(-1, k);
		i += 2;
		k++;
	}
	return sum;
}
