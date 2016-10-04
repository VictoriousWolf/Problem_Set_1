// Problem_set_1.c
// 
// 04/10/2016 Nicholas Lovell
//
// NUMERICAL ERRORS IN PRACTISE
//
// This program looks at 2 mathmatically equal functions and sees how there solutions differ.
// Backward and forward analysis is also performed
// on each function to illusatrte this. 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INCREMENT M_PI/180
#define REL_ERR 0.5e-16
#define	START -2*M_PI
#define	END 2*M_PI
#define	ERR_START 0
#define ERR_END 10e-8
#define ERR_INC 1e-8

double f(double x);
double g(double x);
long double f_forward_err(long double x);
long double g_forward_err(long double x);
double f_backward_err(double x);
double g_backward_err(double x);

int main()
{
	for(double i=START ; i<END ; i+=INCREMENT)
	{
		printf("x : %lf\tf=%.17lf\tg=%.16lf\t",i,f(i),g(i));
		(f(i)==g(i)) ? printf("\n") : printf("Don't match\n");	
	}

	for(long double i=ERR_START;i<ERR_END;i+=ERR_INC)
	{
		printf("Forward error in f(x) = %.16Lf\n",f_forward_err(i));
		printf("Forward error in g(x) = %.16Lf\n",g_forward_err(i));
		f_backward_err(i);
		g_backward_err(i);
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

long double f_forward_err(long double x)
{
	return (1-cosl(x))/powl(x,2) - (f(x));
}

long double g_forward_err(long  double x)
{
	return 2*(powl((sinl(0.5*x)/x),2)) - (g(x));
}

double f_backward_err(double x)
{
//	printf("f:back_err %.17lf    ",sqrt((1-cos(x))/f(x))-x);
	printf("f:back_err %.16lf\n",acos(-pow(x,2)*f(x)+1-x));
	return 0; 
}

double g_backward_err(double x)
{
//	printf("g:back_err %.16lf    ",2*(asin(x*sqrt(g(x)/2)))-x);
        printf("g:back_err %.16lf\n",sin(0.5*x)/sqrt(g(x)/2)-x);
        return 0;
}
