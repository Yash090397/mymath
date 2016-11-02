/*****************************************************************************
 * Copyright (C) Yash Shital Vaishali Nahar naharys15.comp@coep.ac.in
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#ifndef __MATH_H
#define __MATH_H
#define MINIMUM 0.000000000000001
#define LOGe10 2.302585093
#define PI 3.141592654
/* Handle error no in error cases */
#include <errno.h>
/*************/
#  define isfinite(x) __builtin_isfinite (x)
#  define isnan(x) __builtin_isnan (x)
#  define isinf(x) __builtin_isinf_sign (x)
/*enum
  {
    FP_NAN =
#define FP_NAN 0
      FP_NAN,
    FP_INFINITE =
#define FP_INFINITE 1
      FP_INFINITE,
    FP_ZERO =
#define FP_ZERO 2
      FP_ZERO,
    FP_SUBNORMAL =
#define FP_SUBNORMAL 3
      FP_SUBNORMAL,
    FP_NORMAL =
#define FP_NORMAL 4
      FP_NORMAL
  };*/
# define NAN	(__builtin_nanf (""))
# define HUGE_VAL	(__builtin_huge_val())
# define INFINITY	(__builtin_inff())
# define HUGE_VALL	(__builtin_huge_vall())
# define HUGE_VALF	(__builtin_huge_valf())

# define isgreater(x, y)	__builtin_isgreater(x, y)
# define isgreaterequal(x, y)	__builtin_isgreaterequal(x, y)
# define isless(x, y)		__builtin_isless(x, y)
# define islessequal(x, y)	__builtin_islessequal(x, y)
# define islessgreater(x, y)	__builtin_islessgreater(x, y)
# define isunordered(u, v)	__builtin_isunordered(u, v)

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
double exp3(double x); //-- Compute exponential of x
double fabs3(double x ); //-- Compute absolute value of x.
double floor3(double x); //-- Get largest integral value less than x.
double fmod3(double x, double y); //-- Divide x by y with integral quotient and return remainder.
double frexp3(double x, int *expptr); //-- Breaks down x into mantissa and exponent of no.
double labs3(long n); //-- Find absolute value of long integer n.
double log3(double x); //-- Compute log(x).
double log103(double x); //-- Compute log to the base 10 of x.
double modf3(double x, double *intptr); //-- Breaks x into fractional and integer parts.
double pow3(double x, double y); //-- Compute x raised to the power y.
double sqrt3(double x); //-- Compute the square root of x.

#endif
