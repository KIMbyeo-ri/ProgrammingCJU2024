#include <stdio.h>

int main(void)
{
    int num1, num2;
    char ca;
    int answer;

    printf("������ �Է��ϼ��� : ");
    scanf_s("%d %c %d", &num1, &ca, sizeof(ca), &num2);

    switch (ca)
    {
    case '+':
        answer = num1 + num2;
        printf("���: %d\n", answer);
        break;

    case '-':
        answer = num1 - num2;
        printf("���: %d\n", answer);
        break;

    case '*':
        answer = num1 * num2;
        printf("���: %d\n", answer);
        break;

    case '/':
        answer = num1 / num2;
        printf("���: %d\n", answer);
        break;

    default:
        printf("�߸��� ������ �Դϴ�");
        break;



    }
    return 0;
}




                     


         