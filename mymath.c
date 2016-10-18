#include <stdio.h>
#include <stdlib.h>
#include "mymath.h"

double ceil3(double x) {
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
	return 0; //still to be handled
}

double fmod3(double a, double b) {
	return (a - b * floor3(a/b));
}

double fabs3(double term) {
	if(term < 0)
		return (-term);
	else
		return (term);
}

double sin3(double x) {
	//if(x == NaN || x == INFINITY || x == -INFINTY) 
	//	return NaN;
	/*else*/if(x > (2 * PI)) 
			return (sine(fmod3(x, (2 * PI))));
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
	//if(x == NaN || x == INFINITY || x == -INFINTY) 
	//	return NaN;
	/*else*/if(x > (2 * PI)) 
			return (sin3(fmod3(x, (2 * PI))))
	
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
	if(cos3(x) != NaN) {
		y =  (sin3(x)/cos3(x));
		if(sizeof(y) > sizeof(double))
			return HUGE_VAL;
		else
			return y;
	} 
	else 
		return NaN;
}

double sinh3(double x) {
	if(x == NaN)
		return NaN;
	else if(x == INFINITY)
		return INFINITY;
	else if(x == -INFINTY)
		return INFINITY;
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
	if(x == NaN)
		return NaN;
	else if(x == INFINITY || x == -INFINTY)
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
	if(x == NaN)
		return NaN;
	else if(x == INFINITY)
		return 1;
	else if(x == -INFINTY)
		return -1;
	else {
		return 0;//still to be handled
	}
}	

double asin3(double x) {
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
	return ((PI/2) - asin3(x));
}

double atan3(double x) {
	int n = 1;
	double term = x, sum = x;
	while(fobs(term) > MINIMUM) {
		term = term * x * x / ((2 * n) + 1);
		if(n % 2 == 1) 
			sum = sum - term;
		else
			sum = sum + term;
		n++;
	}
	return sum;
}

double atan23(double y, double x) {
	return 0; //still to be handled
}

double log3(double x) {
	if(x == NaN || x < 0)
		return NaN;
	else if(x == 0)
		return -HUGE_VAL;
	else {
		int n = 1;
		double term = (x - 1)/(x + 1); sum = (x - 1)/(x + 1);
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
	
	int n = 1;
	double sum = 1, term = 1;
	while(fabs3(term) > MINIMUM) {
		term = term * x / n;
		sum = sum + term;
		n++;
	}
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
			//Domain error
		}
		else 
			return 	0.0;
	else {
		if(fmod3(y, floor(y)) == 0) {
			if(y < 0) 
				y = -y;	
			term = x; 
			result = 1;
			while(y) {
				if(y % 3 == 1)
					result = result * term;
				if(y % 3 == 2)
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
			if(x < 0)
				return /*-NaN*/1010101;
			else
				return (exp3(y * lg(x)));
		}
			
	}	
}

double sqrt3(double x) {
	if(x == NaN)
		return NaN;
	else if(x < 0)
		//domain error
		return NaN;
	else if(x == 0)
		return 0;
	else
		return exp3((0.50) * log3(x));
}

double modf3(double x, double *ip) {
	if(x == ceil(x)) {
		*ip = x;
		return 0;
	}
	else if(x > 0) {
		*ip = floor(x);
		return (x - floor(x));
	}
	else {
		*ip = ceil(x);
		return (-(ceil(x) - x));
	}
}

double frexp3(double x, int *exp) {
	//if(/*x is power of 2*/) {
	//	return 0;
	//}
	//else {
		if(x == 0) {
			*exp = 0;
			return 0;
		}
		else if(x < 0) {
			double d = lg(2);
			*exp = ceil(lg(-x)/d);
			return ((x / (pow3(2, *exp))));
		}
		else {
			double d = lg(2);
			*exp = ceil(lg(x)/d);
			return (x / (pow3(2, *exp)));
		}	
	//}	
}
	
div_t div3(int number, int denom) {
	return 0; //still left
}

double labs3(long n) {
	return 0; //still left
}

double ldexp3(double x, int exp) {
	return 0; //still left
}

ldiv_t ldiv3(long number, long denom) {
	return 0; //still left
}

void srand3(unsigned seed) {
	return 0; //still left
}









