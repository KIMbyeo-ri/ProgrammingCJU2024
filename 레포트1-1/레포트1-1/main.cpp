#include <stdio.h>

int main(void)
{
	double angle = 0.0; 
	double convert_angle = 0.0;

	printf("각도 입력(0~360 or 그 이상)\n");
	scanf_s("%lf" , &angle);

	convert_angle = angle - 360 * ((int)(angle + 180) / 360);
	
	
	printf("변환된 각도 : %lf", convert_angle);
	
	
	return 0;
}