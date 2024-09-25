#include <stdio.h>



int main(void)
{
	double ft = 0.0;
	double in = 0.0;
	double kg = 0.0;
	double m = 0.0;
	double slug = 0.0;
	printf("ft, in, kg, m, slug를 입력하시오\n");

	scanf_s("%lf %lf %lf %lf %lf", &ft, &in, &kg, &m, &slug);
	printf("result %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf: (ft to m, m to ft, in to m, m to in, slug to kg, kg to slug)", ft * 0.3048, m * 3.281, in * 0.0254, m * 39.37, slug * 14.59, m * 0.068);
	return 0;
}