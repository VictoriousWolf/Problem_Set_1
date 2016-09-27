#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INCREMENT (2*M_PI)/360
#define REL_ERR 0.5e-16

double f(double x);
double g(double x);

int main()
{
	for(double i=-2*M_PI ; i<2*M_PI ; i+=INCREMENT)
	{
		printf("i:%lf\tf=%.17lf\tg=%.17lf\t",i,f(i),g(i));
		(f(i)==g(i)) ? printf("\n") : printf("Don't match\n");	
	}
}

double f(double x)
{
	return  (1-cos(x))/pow(x,2);
}
double g(double x)
{
	return 2*(pow((sin(0.5*x)/x),2));
}
