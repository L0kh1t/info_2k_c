#include <stdio.h>
#include <math.h>

const double eps = 1e-10;

int solve_quadratic(double a, double b, double c, double* px1, double* px2)
{
	double D;
	D = b * b - 4 * a * c;
	if (D < 0)
		return 0;
	else if (D - 0 < eps){
		*px1 = -sqrt(c) * (b / abs(b));
		return 1;
	}
	else {
		*px1 = (-b + sqrt(D)) / (2 * a);
		*px2 = (-b - sqrt(D)) / (2 * a);
		return 2;
	}
}

int main()
{
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	double x1, x2;
	int result;
	result = solve_quadratic(a, b, c, &x1, &x2);
	printf("%i, %lf, %lf", result, x1, x2);
}