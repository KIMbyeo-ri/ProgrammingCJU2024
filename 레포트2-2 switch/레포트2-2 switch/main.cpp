#include <stdio.h>

int main(void)
{
    int num1, num2;

    printf("ù ��° ������ �Է��ϼ���:");
    scanf_s("%d", &num1);

    printf("�� ��° ������ �Է��ϼ���:");
    scanf_s("%d", &num2);

    switch (num2){
        case 0:
            printf("0���� ������ �����ϴ�.\n");
            break;
        default:

            switch (num1 % num2)
            {
            case 0:
                printf("%d�� %d�� ����Դϴ�.\n" , num1 , num2);
                break;

            default:
                printf("%d�� %d�� ����� �ƴմϴ�.\n" , num1 , num2);
                break;

            }
            break;

}
    return 0;
}
