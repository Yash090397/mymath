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
#include <stdio.h>
#include <stdlib.h>
#include "mymath.h"

double ceil3(double x) {
	if( (x - ((int)x) == 0) || isnan(x) || isinf(x))
		return x;
	int temp; double ceil;
	temp = x;
	if(x < 0) {
		ceil = temp;
		return ceil;
	}
	else {
		temp++;
		ceil = temp;
		return ceil;
	}
}

double floor3(double x) {
	if(x - ((int)x) == 0 || isnan(x) || isinf(x))
		return x;
	int temp;
	double floor;
	temp = x;
	if(x < 0) {
		floor = --temp;
		return floor;
	}
	else {
		floor = temp;
		return floor;
	}
}

double fmod3(double a, double b) {
	if(isnan(a) || isnan(a) )
		return NAN;
	if(isinf(a) || b == 0) {
		errno = EDOM;
		return NAN;
	}
	if(a == 0 && b != 0)
		return 0;
	return (a - b * floor3(a/b));
}

double fabs3(double term) {
	if(isnan(term))
		return NAN;
	if(isinf(term) /*|| x == -INFINITY*/)
		return INFINITY;
	if(term < 0)
		return (-term);
	else
		return (term);
}

double sin3(double x) {
	if(isnan(x)) 
		return NAN;
	if(isinf(x)/* || x == -INFINTY*/) {
		errno = EDOM;
		return NAN;
	}
	else if(x > (2 * PI)) 
			return (sin3(fmod3(x, (2 * PI))));
	 else {
		int n = 3;
		double sum = x, term = x;
		while(fabs3(term) > MINIMUM) {
			term = term * x * x / ( n * ( n - 1 ));
			if(n % 4 == 3) 
				sum  = sum - term;
			else 
				sum  = sum + term;
			n = n + 2;
		}
		return sum;
	}
}

double cos3(double x) {
	if(isnan(x)) 
		return NAN;
	if(isinf(x)/* || x == -INFINTY*/) {
		errno = EDOM;
		return NAN;
	}
	else if(x > (2 * PI)) 
			return (cos3(fmod3(x, (2 * PI))));
	
	else {
		int n = 2;
		double sum = 1, term = 1;
		while(fabs3(term) > MINIMUM) {
			term = term * x * x / (n * ( n - 1 ));
			if(n % 4 == 2)
				sum = sum - term;	
			else
				sum = sum + term;
			n = n + 2;
		}		
		return sum;
	}
}

double tan3(double x) {
	double y;
	if(cos3(x) != NAN) {
		y =  (sin3(x)/cos3(x));
		if(sizeof(y) > sizeof(double))
			return HUGE_VAL;
		else
			return y;
	} 
	else 
		return NAN;
}

double sinh3(double x) {
	if(isnan(x))
		return NAN;
	else if(isinf(x))
		return INFINITY;
	//else if(x == -INFINTY)
	//	return INFINITY;
	else {		
		int n = 3;
		double sum = x, term = x;
		while(fabs3(term) > MINIMUM) {
			term = term * x * x / ( n * ( n - 1 ));
			sum = sum + term;
			n = n + 2;
		}
		if(sizeof(sum) > sizeof(double))
			return HUGE_VAL;
		else
			return sum;
	}
}

double cosh3(double x) {
	if(isnan(x))
		return NAN;
	else if(isinf(x)/* || x == -INFINTY*/)
		return INFINITY;
	else {
		int n = 2;
		double sum = 1, term = 1;
		while(fabs3(term) > MINIMUM) {
			term = term * x * x / ( n * ( n - 1 ));
			sum = sum + term;
			n = n + 2;
		}
		if(sizeof(sum) > sizeof(double))
			return HUGE_VAL;
		else
			return sum;
	}
}

double tanh3(double x) {
	if(isnan(x))
		return NAN;
	else if(isinf(x))
		return 1;
	//else if(x == -INFINTY)
	//	return -1;
	else {
		return sinh3(x) / cosh3(x);
	}
}	

double asin3(double x) {
	if(fabs3(x) >= 1) {
		errno = EDOM;
		return NAN;
	}
	if(isnan(x))
		return NAN;
	if(x == 0)
		return 0;
	int n = 3;
	double term = ((x * x * x)/6), sum = x + ((x * x * x)/6);
	while(term > MINIMUM) {
		term = term * x * x * (n * n) / ((n + 2) * (n + 1));
		sum = sum + term;
		n = n + 2;
	}
	return sum;
}

double acos3(double x) {
	if(fabs3(x) >= 1) {
		errno = EDOM;
		return NAN;
	}
	if(isnan(x))
		return NAN;
	if(isinf(x)) {
		errno = EDOM;
		return NAN;
	}
	if(x == 1)
		return 0;
	return ((PI/2) - asin3(x));
}

double atan3(double x) {
	if(isnan(x))
		return NAN;
	if(x == 0)
		return 0;
	if(isinf(x))
		return PI/2;
	if(x > 1)
		return atan3(fmod3(x, 1));
	int n = 1;
	double term = x, sum = x;
	while(fabs3(term) > MINIMUM) {
		term = term * x * x / ((2 * n) + 1);
		if(n % 2 == 1) 
			sum = sum - term;
		else
			sum = sum + term;
		n++;
	}
	if(sum > (PI/2))
		sum = fmod3(sum, (PI/2));
	else if(sum < (-(PI/2)))
		sum = fmod3(sum, (-PI/2));
	return sum;
}

double atan23(double y, double x) {
     /*If y is +0 (-0) and x is less than 0, +pi (-pi) is returned.

       If y is +0 (-0) and x is greater than 0, +0 (-0) is returned.

       If y is less than 0 and x is +0 or -0, -pi/2 is returned.

       If y is greater than 0 and x is +0 or -0, pi/2 is returned.

       If either x or y is NaN, a NaN is returned.

       If y is +0 (-0) and x is -0, +pi (-pi) is returned.

       If y is +0 (-0) and x is +0, +0 (-0) is returned.
*/
	if(x == 0) {
		if(y < 0)
			return (-PI/2);
		else if(y > 0)
			return (PI/2);
		else
			return 0;
	}
	if(y == 0) {
		if(x < 0)
			return (PI);
		if(x > 0)
			return 0;
	}
	double tmp;
	tmp = atan3(y / x);
	return tmp;
}

double log3(double x) {
	if(isnan(x))
		return NAN;
	else if(isinf(x)) 
		return INFINITY;
	else if(x == 0) {
		errno = ERANGE;
		return -HUGE_VAL;
	}
	else if(x < 0) {
		errno = EDOM;
		return NAN;
	}
	else if(x == 1)
		return 0;
	else {
		int n = 1;
		double term = (x - 1)/(x + 1), sum = (x - 1)/(x + 1);
		while(term > MINIMUM) {
			term = term * (x - 1) * (x - 1) * ((2 * n) - 1) / ((x + 1) * (x + 1) * ((2 * n) + 1));
			sum = sum + term;
			n++;
		}
		sum = sum * 2;
		return sum;
	}
} 

double exp3(double x) {
	if(isnan(x))
		return NAN;
	if(isinf(x))
		return INFINITY;
	//if(x == -INFINITY)
	//	return 0;
	if(x == 0)
		return 1;
	int n = 1;
	double sum = 1, term = 1;
	while(fabs3(term) > MINIMUM) {
		term = term * x / n;
		sum = sum + term;
		n++;
	}
	if(sizeof(sum) > sizeof(double)) {
		errno = ERANGE;
		return HUGE_VAL;
	} else		
	return sum;
}

double log103(double x) {
	return (log3(x)/LOGe10);
}

double pow3(double x, double y) {
	long term, result;
	int sign = 0, z;
	z = y;
	if(x == 1 || y == 0)
		return 1.0;
	if(x==0) 
		if(y <= 0) {
			errno = EDOM;
			return NAN;
		}
		else 
			return 	0.0;
	else {
		if(fmod3(y, floor3(y)) == 0) {
			if(y < 0) 
				y = -y;	
			term = x; 
			result = 1;
			while(y) {
				if((int)y % 3 == 1)
					result = result * term;
				if((int)y % 3 == 2)
					result = result * term * term;
				y /= 3;
				term = term * term * term;
			}
			if(z < 0) 
				return (1.0)/result;	
			else 
				return (double)result;	
		}
		else {
			if(x < 0) {
				errno = EDOM;
				return NAN;
			}
			else
				return (exp3(y * log3(x)));
		}
			
	}	
}

double sqrt3(double x) {
	if(isnan(x))
		return NAN;
	if(isinf(x))
		return INFINITY;
	else if(x < 0) {
		errno = EDOM;
		return NAN;
	}
	else if(x == 0)
		return 0;
	else
		return exp3((0.50) * log3(x));
}

double modf3(double x, double *ip) {
	if(isnan(x)) {
		*ip = NAN;
		return NAN;
	}
	if(isinf(x)) {
		*ip = INFINITY;
		return 0;
	}
	if(x == ceil3(x)) {
		*ip = x;
		return 0;
	}
	else if(x > 0) {
		*ip = floor3(x);
		return (x - floor3(x));
	}
	else {
		*ip = ceil3(x);
		return (-(ceil3(x) - x));
	}
}

double frexp3(double x, int *exp) {
	if(isnan(x)) {
		return NAN;
	}
	if(isinf(x)) {
		return INFINITY;
	}
	double d = log3(2);
	double y = (log3(fabs3(x))/d);
	if(ceil3(y) == y) { 
		*exp = y/2;
		return (0.5);
	}
	else {
		if(x == 0) {
			*exp = 0;
			return 0;
		}
		else {
			*exp = ceil3(y);
			return (x / (pow3(2, *exp)));
		}	
	}	
}

double ldexp3(double x, int exp) {
	double ldexp2;
	if(isnan(x))
		return NAN;
	if(isinf(x))
		return INFINITY;
	if(exp == 0)
		return x;
	ldexp2 = (x * pow3(2, exp));
	if(sizeof(ldexp2) > sizeof(double)) {
		errno = ERANGE;
		return HUGE_VAL;
	} else
		return ldexp2;
}

double labs3(long n) {
	if(n >= 0)
		return (double)(n);
	else
		return (double)(-n);
}
