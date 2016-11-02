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
 
 /*Use of this code:
 This program reads from a tab separated txt file with function name as first column and arguments as following columns.
 It compares the values of the function from math.h & mymath.h; gives a pass if values match, else fail
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>
#include <stdarg.h>
#include "mymath.h"
#define MAXX 256

enum states {sin4 = 27105, cos4 = 28630, tan4 = 25058, asin4 = 57802, acos4 = 54992, atan4 = 58050, atan24 = 58100, sinh4 = 53729, cosh4 = 55254, tanh4 = 51682, ceil4 = 53708, floor4 = 56391, fmod4 = 53717, modf4 = 54737, fabs4 = 54472, exp4 = 30933, log4 = 28627, log104 = 41219, pow4 = 28647, sqrt4 = 58853, frexp4 = 60219, ldexp4 = 56641, labs4 = 54478};

typedef struct data {
	char fn_name[MAXX];
	double arg1, arg2;
} data;

int usage() {
	fprintf(stderr, "usage:./launch_mymath_lib <filename>\n");
	return EINVAL;
}

int main(int argc, char *argv[]) {
	FILE *fp;
	data d[MAXX];
	int i, n = 0, p = 0, f = 0, tmp;
	float pc;
	double tmp1, tmp2;
	if(argc < 2)
		return usage();

	fp = fopen(argv[1], "r");
	if(fp == NULL) {
		perror("Cannot open file:");
		exit(errno);
	}
	while(!feof(fp)) {
		fscanf(fp, "%s%lf%lf", d[n].fn_name, &d[n].arg1, &d[n].arg2);
		n++;		
	}
	int hash(char *str) {
		int number = 0;
		while (*str) {
			number += *str++;
			if(*str)
				number += ((int) *str++) << 8;
		}
		return number;
	}
	for(i = 0; i < n; i++) {
		printf("%s\t%lf\t%lf\n", d[i].fn_name, d[i].arg1, d[i].arg2);
		switch(hash(d[i].fn_name)) {
			case sin4:
				if(sin(d[i].arg1) == sin3(d[i].arg1) || fabs(sin(d[i].arg1) - sin3(d[i].arg1)) <= 0.1) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case cos4:
				if(cos(d[i].arg1) == cos3(d[i].arg1) || fabs(cos(d[i].arg1) - cos3(d[i].arg1)) <= 0.1) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case tan4:
				if(tan(d[i].arg1) == tan3(d[i].arg1) || fabs(tan(d[i].arg1) - tan3(d[i].arg1)) <= 0.1) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case asin4:
				if(asin(d[i].arg1) == asin3(d[i].arg1) || fabs(asin(d[i].arg1) - asin3(d[i].arg1)) <= 0.1) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case acos4:
				if(acos(d[i].arg1) == acos3(d[i].arg1) || fabs(acos(d[i].arg1) - acos3(d[i].arg1)) <= 0.1) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case atan4:
				if(atan(d[i].arg1) == atan3(d[i].arg1) || fabs(atan(d[i].arg1) - atan3(d[i].arg1)) <= 0.1) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case atan24:
				if(atan2(d[i].arg1, d[i].arg2) == atan23(d[i].arg1, d[i].arg2) || fabs(atan2(d[i].arg1, d[i].arg2) - atan23
				  (d[i].arg1, d[i].arg1)) <= 0.1) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case sinh4:
				if(sinh(d[i].arg1) == sinh3(d[i].arg1) || fabs(sinh(d[i].arg1) - sinh3(d[i].arg1)) <= 0.1) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case cosh4:
				if(cosh(d[i].arg1) == cosh3(d[i].arg1) || fabs(cosh(d[i].arg1) - cosh3(d[i].arg1)) <= 0.1) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case tanh4:
				if(tanh(d[i].arg1) == tanh3(d[i].arg1) || fabs(tanh(d[i].arg1) - tan3(d[i].arg1)) <= 0.1) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case ceil4:
				if(ceil(d[i].arg1) == ceil3(d[i].arg1)) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case floor4:
				if(floor(d[i].arg1) == floor3(d[i].arg1)) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case fmod4:
				if(fmod(d[i].arg1, d[i].arg2) == fmod3(d[i].arg1, d[i].arg2)) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case modf4:
				if(modf(d[i].arg1, &tmp1) == modf3(d[i].arg1, &tmp2)) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case fabs4:
				if(fabs(d[i].arg1) == fabs3(d[i].arg1)) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case exp4:
				if((exp(d[i].arg1) == exp3(d[i].arg1)) || (fabs(exp(d[i].arg1) - exp(d[i].arg1)) <= 0.1)) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case log4:
				if((log(d[i].arg1) == log3(d[i].arg1)) || (fabs(log(d[i].arg1) - log3(d[i].arg1)) <= 0.1)) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case log104:
				if((log10(d[i].arg1) == log103(d[i].arg1)) || (fabs(log10(d[i].arg1) - log103(d[i].arg1)) <= 0.1)) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case pow4:
				if(pow(d[i].arg1, d[i].arg2) == pow3(d[i].arg1, d[i].arg2) || fabs(pow(d[i].arg1, d[i].arg2) - pow3
				  (d[i].arg1, d[i].arg1)) <= 0.1) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case sqrt4:
				if((sqrt(d[i].arg1) == sqrt3(d[i].arg1)) || (fabs(sqrt(d[i].arg1) - sqrt3(d[i].arg1)) <= 0.1)) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case frexp4:
				if(frexp(d[i].arg1, &tmp) == frexp3(d[i].arg1, &tmp)) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			case ldexp4:
				break;
			case labs4:
				if(labs((long)d[i].arg1) == labs3((long)d[i].arg1)) {
					printf("Case %d: Pass\n", i);
					p++;
				}
				else {
					printf("Case %d: Fail\n", i);
					f++;
				}
				break;
			default:
				printf("Case %d: Invalid Function Name\n", i);
				break;
		}
	}
	pc = (float)(p) / (float)(p + f) * 100.0;
	printf("No of cases passed: %d\n", p);
	printf("No of cases failed: %d\n", f);
	printf("Pass percentage: %f\n", pc);
	fclose(fp);
	return 0;
}
