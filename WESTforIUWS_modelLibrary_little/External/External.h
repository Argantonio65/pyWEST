#ifndef _External_h
#define _External_h

#include <stdio.h>
#include <math.h>

#ifdef __cplusplus
extern "C"
{
#endif


double FbkPrimeV(double C, double a, double b);

double FbkPrimeV_DExp(double C, double a, double b, double d);

double LOG2(double n );

double Fmax(double a, double b);

double CHat(double par1, double par2, double a, double b, double TOL);

double CHat_DExp(double par1, double par2, double par3, double a, double b, double TOL);

double dcomp(double C, double a, double b, double rhos, double rhof, double par1, double par2, double Ccrit);

double IntDcomp(double a, double b, double v0, double rv, double rhos, double rhof, double par1, double par2, double Ccrit);

double Djnum(double C1, double C2, double Ccrit, double v0, double rv, double rhos, double rhof, double par1, double par2);

double NewtonRaphson(double d, double Q, double W, double S, double z, double n, double Niter);

#ifdef __cplusplus
}
#endif



#endif

