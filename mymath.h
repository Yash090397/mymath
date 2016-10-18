#ifndef __MATH_H
#define __MATH_H
#define MINIMUM 0.0000000000001
#define LOGe10 2.302585093
#define PI 3.141592654
/* Handle error no in error cases */
#include <errno.h>
/* Get machine-dependent vector math functions declarations.  */
#include <bits/math-vector.h>

/* Get machine-dependent HUGE_VAL value (returned on overflow).
   On all IEEE754 machines, this is +Infinity.  */
#include <bits/huge_val.h>
#ifdef __USE_ISOC99
# include <bits/huge_valf.h>
# include <bits/huge_vall.h>

/* Get machine-dependent INFINITY value.  */
# include <bits/inf.h>

/* Get machine-dependent NAN value (returned for some domain errors).  */
# include <bits/nan.h>
#endif /* __USE_ISOC99 */

/* Get general and ISO C99 specific information.  */
#include <bits/mathdef.h>

double sin3(double x);  //-- Compute sine of angle in radians.
double cos3(double x);  //-- Compute cosine of angle in radians.
double tan3(double x);  //-- Compute tangent of angle in radians.
double sinh3(double x); //-- Compute the hyperbolic sine of x.
double cosh3(double x); //-- Compute the hyperbolic cosine of x.
double tanh3(double x); //-- Compute the hyperbolic tangent of x.
double asin3(double x); //-- Compute arc sine of x.
double acos3(double x); //-- Compute arc cosine of x.
double atan3(double x); //-- Compute arc tangent of x.
double atan23(double y, double x); //-- Compute arc tangent of y/x, using the signs of both arguments to determine the quadrant of the return value.
double ceil3(double x); //-- Get smallest integral value that exceeds x.
div_t div3(int number, int denom); //-- Divide one integer by another.
double exp3(double x); //-- Compute exponential of x
double fabs3(double x ); //-- Compute absolute value of x.
double floor3(double x); //-- Get largest integral value less than x.
double fmod3(double x, double y); //-- Divide x by y with integral quotient and return remainder.
double frexp3(double x, int *expptr); //-- Breaks down x into mantissa and exponent of no.
double labs3(long n); //-- Find absolute value of long integer n.
double ldexp3(double x, int exp); //-- Reconstructs x out of mantissa and exponent of two.
ldiv_t ldiv3(long number, long denom); //-- Divide one long integer by another.
double log3(double x); //-- Compute log(x).
double log103(double x); //-- Compute log to the base 10 of x.
double modf3(double x, double *intptr); //-- Breaks x into fractional and integer parts.
double pow3(double x, double y); //-- Compute x raised to the power y.
double sqrt3(double x); //-- Compute the square root of x.
void srand3(unsigned seed); //-- Set a new seed for the random number generator (rand).
#endif
