#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "mymath.h"

double sine(double x) {
	//if(x == NaN || x == INFINITY || x == -INFINTY) 
	//	return NaN;
	/*else*/if(x > (2 * PI)) 
			return (sine(fomod(x, (2 * PI))));
	 else {
		int n = 3;
		double sum = x, term = x;
		while(foabs(term) > MINIMUM) {
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

double cose(double x) {
	//if(x == NaN || x == INFINITY || x == -INFINTY) 
	//	return NaN;
	/*else*/if(x > (2 * PI)) 
			return (sine(fomod(x, (2 * PI))))
	
	else {
		int n = 2;
		double sum = 1, term = 1;
		while(foabs(term) > MINIMUM) {
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

double tane(double x) {
	double y;
	if(cos(x) != NaN) {
		y =  (sin(x)/cos(x));
		if(sizeof(y) > sizeof(double))
			return HUGE_VAL;
		else
			return y;
	} 
	else 
		return NaN;
}

double sinhe(double x) {
	if(x == NaN)
		return NaN;
	else if(x == INFINITY)
		return INFINITY;
	else if(x == -INFINTY)
		return INFINITY;
	else {		
		int n = 3;
		double sum = x, term = x;
		while(foabs(term) > MINIMUM) {
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

double coshe(double x) {
	if(x == NaN)
		return NaN;
	else if(x == INFINITY || x == -INFINTY)
		return INFINITY;
	else {
		int n = 2;
		double sum = 1, term = 1;
		while(foabs(term) > MINIMUM) {
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

double tanhe(double x) {
	if(x == NaN)
		return NaN;
	else if(x == INFINITY)
		return 1;
	else if(x == -INFINTY)
		return -1;
	else {
		
	

double asine(double x) {
	int n = 3;
	double term = ((x * x * x)/6), sum = x + ((x * x * x)/6);
	while(term > MINIMUM) {
		term = term * x * x * (n * n) / ((n + 2) * (n + 1));
		sum = sum + term;
		n = n + 2;
	}
	return sum;
}

double acose(double x) {
	return ((PI/2) - asin(x));
}

double atane(double x) {
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

double lg(double x) {
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

double expo(double x) {
	
	int n = 1;
	double sum = 1, term = 1;
	while(foabs(term) > MINIMUM) {
		term = term * x / n;
		sum = sum + term;
		n++;
	}
	return sum;
}

double lg10(double x) {
	return (lg(x)/lgE10);
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
}
double fomod(double a, double b) {
	return (a - b * floor(a/b));
}

double foabs(double term) {
	if(term < 0)
		return (-term);
	else
		return (term);
}


		














