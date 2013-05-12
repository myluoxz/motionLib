#ifndef SPLINEINTERP_H
#define SPLINEINTERP_H

#include "CVector3f.h"
class SplineInterp
{
public:
	/*input the num of point*/
	SplineInterp();
	~SplineInterp(void);
	/*
	input:
	x
	y 
	the number of point 
	First derivative at 0 and n-1

	output:
	Polynomial parametric
	S(x) = coef[i*4 + 0] * (x[i+1] - x)^3 + coef[i*4 + 1] * (x - x[i])^3 + coef[i*4 + 2] * (x[i+1] - x) + coef[i*4 + 3] * (x - x[i])
	i belong to [0,n-2]
	*/

	void getCubicSplinePolynomial(const float *x,const CVector3f *y,CVector3f *coef,\
		const int n,const CVector3f &d20,const CVector3f &d2n);//

	/*interpolation
	input:
	coef
	i ,p_x interval
	p_x ,parameter x
	x ,x sequence
	res_y, result y
	*/
	void getCubicSplineInterpValue(const CVector3f *coef,const int i,const float p_x,const float *x,CVector3f &res_y);
private:
	/*note: b and d will be overload*/
	void thomas(float *a,float *b,float *c,CVector3f *x,CVector3f *d,const int n);//[0,n-1]

private:

};
#endif


