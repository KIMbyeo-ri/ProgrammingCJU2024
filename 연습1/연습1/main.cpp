#include <stdio.h>

int main(void)
{
	double 삼각형밑변, 삼각형높이, 사각형가로, 사각형세로, 원반지름 = 0;
	double 삼각형넓이, 사각형넓이, 구의표면적, 구의체적 = 0;
	const int pi = 3.141592;




	printf("삼각형의 밑변, 높이, 사각형 가로, 세로, 원반지름을 입력하시오\n");
	scanf_s("%lf%lf%lf%lf%lf", &삼각형밑변, &삼각형높이, &사각형가로, &사각형세로, &원반지름);

	printf("삼각형넓이 %.2lf, 사각형넓이 %.2lf, 구의표면적 %.2lf, 구의체적 %.2lf\n", 삼각형밑변 * 삼각형높이 / 2, 사각형가로 * 사각형세로, 4 * pi * 원반지름 * 원반지름, 4 / 3 * pi * 원반지름 * 원반지름 * 원반지름);

	return 0;
	
}