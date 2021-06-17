
#include <stdio.h>
#include <math.h>
#include <complex.h>
 
double PI;
typedef double complex cplx;
unsigned entry_size;

void _fft(cplx buf[], cplx out[], int n, int step)
{
	if (step < n) {
		_fft(out, buf, n, step * 2);
		_fft(out + step, buf + step, n, step * 2);
 
		for (int i = 0; i < n; i += 2 * step) {
			cplx t = cexp(-I * PI * i / n) * out[i + step];
			buf[i / 2]     = out[i] + t;
			buf[(i + n)/2] = out[i] - t;
		}
	}
}
 
void fft(cplx buf[], int n)
{
	cplx out[n];
	for (int i = 0; i < n; i++) out[i] = buf[i];
 
	_fft(buf, out, n, 1);
}
 
 
void show(const char * s, cplx buf[]) {
	printf("%s", s);
	for (int i = 0; i < entry_size; i++)
		if (!cimag(buf[i]))
			printf("%g ", creal(buf[i]));
		else
			printf("(%g, %g) ", creal(buf[i]), cimag(buf[i]));
	printf("\n");
}
 
int main()
{
	PI = atan2(1, 1) * 4;
	cplx buf[] = {0, sin(PI/8), sin(PI/4), sin(3*PI/8), sin(PI/2), sin(5*PI/8), sin(3*PI/4), sin(7*PI/8), sin(PI),
					sin(PI+PI/8), sin(PI+PI/4), sin(PI+3*PI/8), sin(PI+PI/2), sin(PI+5*PI/8), sin(PI+3*PI/4), sin(PI+7*PI/8)};
	entry_size = sizeof(buf)/sizeof(cplx);
	printf("Size of entry: %d\n", entry_size);
 
	show("Data: ", buf);
	fft(buf, entry_size);
	show("FFT : ", buf);
 
	return 0;
}
 