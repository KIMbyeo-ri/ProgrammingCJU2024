#include <stdio.h>
#include <math.h>

double sin_c(double x);
double cos_c(double x);

int main(void)
{
    double angle = 0.0;
    double sin_r, cos_r;

    printf("���� �Է� (0-180):");
    scanf_s("%lf", &angle);

    //sin, cos �� ���
    sin_r = sin_c(angle);
    cos_r = cos_c(angle);

    //��� ���
    printf("sin(%.0lf) = %.6lf\n", angle, sin_r);
    printf("cos(%.0lf) = %.6lf\n", angle, cos_r);

    return 0;
}

double sin_c(double x)
{
    double pi = 3.141592;
    double radian = x * pi / 180.0; //������ �������� ��ȯ
    return sin(radian); 
}

double cos_c(double x)
{
    double pi = 3.141592;
    double radian = x * pi / 180.0; //������ �������� ��ȯ
    return cos(radian);
}
