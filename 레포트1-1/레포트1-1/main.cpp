#include <stdio.h>

int main(void)
{
	double angle = 0.0; 
	double convert_angle = 0.0;

	printf("���� �Է�(0~360 or �� �̻�)\n");
	scanf_s("%lf" , &angle);

	convert_angle = angle - 360 * ((int)(angle + 180) / 360);
	
	
	printf("��ȯ�� ���� : %lf", convert_angle);
	
	
	return 0;
}