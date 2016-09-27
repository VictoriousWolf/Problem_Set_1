\\ Created by Nicholas Lovell 
\\ Edited last 27/9/2016
\\
\\ NUMERICAL ERRORS IN PRACTISE
\\
\\ This program looks at 2 functions and sees how there solutions differ from
\\ the mathermatical soultions. Backward and forward analysis is also performed
\\ on each function to illusatrte this. 

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

int main()
{
	for(double i=START ; i<END ; i+=INCREMENT)
	{
		printf("i:%lf\tf=%.17lf\tg=%.17lf\t",i,f(i),g(i));
		(f(i)==g(i)) ? printf("\n") : printf("Don't match\n");	
	}

	for(double i=ERR_START;i<ERR_END;i+=ERR_INC)
	{
		
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

double f_forward_err(double)
{
	
}

double g_forward_err(double)
{

}

double f_backward_err(double)
{

}

double g_backward_err(double)
{

}
