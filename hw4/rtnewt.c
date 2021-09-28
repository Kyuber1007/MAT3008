#include <stdio.h>
#include <math.h>
#define JMAX 1000
float rtnewt(void (*funcd)(float, float *, float *), float x1, float x2,
			 float xacc)
{
	void nrerror(char error_text[]);
	int j, sum = 0;
	float df, dx, f, rtn;

	rtn = 0.5 * (x1 + x2);
	for (j = 1; j <= JMAX; j++)
	{
		sum++;
		(*funcd)(rtn, &f, &df);
		dx = f / df;
		rtn -= dx;
		if ((x1 - rtn) * (rtn - x2) < 0.0)
			nrerror("Jumped out of brackets in rtnewt");
		if (fabs(dx) < xacc)
		{
			printf("반목문 횟수: %d\n", sum);
			return rtn;
		}
	}
	nrerror("Maximum number of iterations exceeded in rtnewt");
	return 0.0;
}
#undef JMAX