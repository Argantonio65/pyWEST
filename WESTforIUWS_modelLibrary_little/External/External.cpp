#include <stdio.h>
#include <math.h>
#include "External.h"

double FbkPrimeV(double C, double a, double b)
{

	double temp;
		temp=a*exp(-b*C)*(1-b*C);
	return temp;

}

double FbkPrimeV_DExp(double C, double a, double b, double d)
{

	double temp;
		temp=a*(exp(-b*C)*(1-b*C)-exp(-d*C)*(1-d*C));
	return temp;

}


 double LOG2(double n )  // Calculates log2 of number.
{
    double temp, ln, l2, nr;

	// log(n)/log(2) is log2.
	nr=2;
	ln=log(n);
	l2=log(nr);
    temp= ln / l2;
	return temp;
}

 double Fmax(double a, double b)
 {
 double max;
 if(a<=b)
 {max=b;}
 else
 {max=a;}
 return max;
 }

double CHat(double par1, double par2, double a, double b, double TOL)
{

	double NBRITER, i;
	double fa, root, fr;

	NBRITER=floor(LOG2((b-a)/TOL));
	fa=FbkPrimeV(a, par1, par2);
	root=(a+b)/2;

	for(i=1; i<=NBRITER; i++)
	{
		fr=FbkPrimeV(root, par1, par2);
		if (fr*fa<=0)
		{
		b=root;
		}
		else
		{
		a=root;
		fa=fr;
		}
	root=(a+b)/2;
	}
	return root;
}

double CHat_DExp(double par1, double par2, double par3, double a, double b, double TOL)
{

	double NBRITER, i;
	double fa, root, fr;

	NBRITER=floor(LOG2((b-a)/TOL));
	fa=FbkPrimeV_DExp(a, par1, par2, par3);
	root=(a+b)/2;

	for(i=1; i<=NBRITER; i++)
	{
		fr=FbkPrimeV_DExp(root, par1, par2, par3);
		if (fr*fa<=0)
		{
		b=root;
		}
		else
		{
		a=root;
		fa=fr;
		}
	root=(a+b)/2;
	}
	return root;
}


double NewtonRaphson(double d, double Q, double W, double S, double z, double n, double Niter)
{
	/*
	Returns the depth associated to a trapezoidal section and a flow Q. The parameters of the section are; W: width, S: long slope, z: lateral slope, n: Manning.
	Solution is provided by a NewtonRaphson approximation using Niter iterations.
	*/
	double i, d_out;
	double A, B, P, f, fp;
	d_out = d;
	for (i=0; i <=Niter; i++)
	{	
		A = d_out * (W + d_out* z);
		B = W + 2* d_out*z;
		P = W + 2*d_out*sqrt(1+pow(z,2));
		
		f = ((sqrt(S)/n)*(pow(A, 5.0/3.0)/ pow(P,2.0/3.0)) ) - Q;
		fp = ((sqrt(S)/(3*n))*(pow(A,2.0/3.0)/pow(P,2.0/3.0)))*( (5*B*P - 4*sqrt(1+z*z)*A )/P);
		
		d_out = d_out - f / fp;
		
		//d_out = d_out - ((sqrt(S)/n) * pow(d_out * (W + z * d_out),(5.0/3.0)) / (pow(W + 2 * d_out * sqrt(1+ pow(z,2)),(2.0/3.0)) ) - Q) / (( 5*sqrt(S)*(W + 2*z*d_out)*pow(d_out * (W + z *d_out),(2.0/3.0)) ) / ( 3*n * pow(W + 2*d_out*sqrt(1+ pow(z,2)),(2.0/3.0))) - ( 4*sqrt(S)* sqrt(1+ pow(z,2)) *pow(d_out * (W + z *d_out),(5.0/3.0))) / ( 3*n* pow(W + 2*d_out*sqrt(1+ pow(z,2)),(5.0/3.0))));	
	}
	return d_out;
}








/*double dcomp(double C, double a, double b, double rhos, double rhof, double par1, double par2, double Ccrit)
{

	double comp, SigmaPrime, Vhs, gh1, gh2, g;
		gh1=9.81;
		gh2=3600;
		g=gh1*gh2^2;
		SigmaPrime=par1*1/(C-Ccrit+par2);
		Vhs=a*exp(-b*C)*(1-b*C);
		comp=rhos*Vhs*SigmaPrime/(g*(rhos-rhof));
	return comp;
}

double IntDcomp(double a, double b, double v0, double rv, double rhos, double rhof, double par1, double par2, double Ccrit)
{
	int L=16,i;
	double alphake,betake,I,temp,x;
	double wl[ ]={2.7152e-2,6.2253e-2,9.5158e-2,1.2462e-1,1.4959e-1,1.6915e-1,1.826034150449236e-1,1.894506104550684e-1,1.894506104550684e-1,1.826034150449236e-1,1.691565193950026e-1,1.495959888165768e-1,1.246289712555339e-1,9.515851168249290e-2,6.225352393864778e-2,2.715245941175406e-2};
	double nl[ ]={9.894009349916499e-1,9.445750230732326e-1,8.656312023878319e-1,7.554044083550031e-1,6.178762444026438e-1,4.580167776572273e-1,2.816035507792589e-1,9.501250983763748e-2,-9.501250983763748e-2,-2.816035507792589e-1,-4.580167776572273e-1,-6.178762444026438e-1,-7.554044083550031e-1,-8.656312023878319e-1,-9.445750230732326e-1,-9.894009349916499e-1};

	alphake=(b-a)/2;
	betake=(b+a)/2;
	I=0;

	for(i=0; i<L; i++)
	{
		x=(alphake*nl[i]+betake)*wl[i];
		temp=dcomp(x,v0,rv,rhos,rhof,par1,par2,Ccrit);
		I += temp;
	}
	return I;
}
double Djnum(double C1, double C2, double Ccrit, double v0, double rv, double rhos, double rhof, double par1, double par2)
{
	double b,a, D;
	a=Fmax(C1,Ccrit);
	b=Fmax(C2,Ccrit);

	if(a==b)
	{
	D=0;
	}

	else
	{
	D=IntDcomp(a,b,v0,rv,rhos,rhof,par1,par2,Ccrit);
	}

	return D;
}*/

/*double Djnum(double C[], int NrOfLayers, double Ccrit, double v0, double rv, double rhos, double rhof, double par1, double par2)
{
	double b,a;
	double D[ ];
	int i;
	b=Fmax(C[0],Ccrit);
	for(i=0;i<(NrOfLayers-1);i++)
	{
		a=b;
		b=Fmax(C[i+1],Ccrit);
		if(a==b)
		{
		D[i]=0;
		}
		else
		{
		D[i]=IntDcomp(a,b,v0,rv,rhos,rhof,par1,par2,Ccrit);
		}
	}
	return D;
}
*/


/*int main()
{
double v0=0.0036;
double rv=0.218;
double C0=0;
double Cmax=20;
double T=1e-15;

printf("\n\nFbk %lf \n\n",CHat(v0,rv,C0,Cmax,T));


return 0;
}
*/