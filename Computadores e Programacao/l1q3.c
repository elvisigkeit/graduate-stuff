#include <stdio.h>

void sub1(int *xp, int *yp, int *zp)
{
	int tx = *xp;
	int ty = *yp;
	int tz = *zp;
	*yp = tx;
	*zp = ty;
	*xp = tz;
}
