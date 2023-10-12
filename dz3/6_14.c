#include <stdio.h>
#include <string.h>
struct point { int x; int y; };
struct color_point { int x; int y; char s[10]; };
struct q_number {int m; int n; };
struct complex_number { struct q_number a; struct q_number b; };

struct point make_point(int x, int y);
struct color_point make_cpoint(int x, int y, char str[10]);

struct point make_point(int x, int y)
{
	struct point pp;
	pp.x=x;
	pp.y=y;
	return pp;
}

struct color_point make_cpoint(int x, int y, char str[10])
{
	struct color_point cp;
	cp.x=x;
	cp.y=y;
	strcpy(cp.s, str);
	return cp;
}

struct q_number make_qnumber(int x, int y)
{
	struct q_number qn;
	qn.n=x;
	qn.m=y;
	return qn;
}

struct complex_number make_cnumber(int x, int y, int x2, int y2)
{
	struct complex_number cn;
	struct q_number q1, q2;
	cn.a= make_qnumber(x,  y);
	cn.b= make_qnumber(x2, y2);
	return cn;
}



int main(int argc, char **argv)
{
	struct color_point { int x; int y; char s[10]; };
	struct q_number {int m; int n; };
	struct complex_number { struct q_number a; struct q_number b; };
	
	struct point p1, p2;
	struct color_point cp1, cp2;
	struct q_number q1, q2;
	struct complex_number cn1, cn2;
	int h=4, j=8;
	
	p1 = make_point(h, j);
	
	return 0;
}



