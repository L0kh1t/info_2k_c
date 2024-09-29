#include <stdio.h>
#include <math.h>

const float step = 1e-2;
const double eps = 1e-14;

double function(float t, double x)
{
	return pow(t, x - 1) * exp(-t);
}

double gamma(double x)
{
	double result = 0.0;
	float t = 0.0;
	double S = 0.0;
	do {
		result += S;
		S = (function(t, x) + function(t + step, x)) * step/2;
		t += step;
		printf("%lf\n", S*pow(10, 10));
	} while (S > eps);
	return result;
}

int main()
{
	double x;
	scanf("%lf", &x);
	printf("%lf", gamma(x));
}
