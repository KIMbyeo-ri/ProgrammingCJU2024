#include <stdio.h>

int main(void)
{
    int num1, num2;

    printf("ù ��° ������ �Է��ϼ���:");
    scanf_s("%d", &num1);
    
    printf("�� ��° ������ �Է��ϼ���:");
    scanf_s("%d", &num2);

    if (num2 != 0 && num1 % num2 == 0) {
        printf("%d�� %d�� ����Դϴ�.\n", num1, num2);
    }
    else {
        printf("%d�� %d�� ����� �ƴմϴ�.\n", num1, num2);
    }

    return 0;
}