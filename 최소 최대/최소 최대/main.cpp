#include <stdio.h>

int main(void) {
    int num1;
    int num2;
    int gcd;
    int lcm;
    int a;
    int b;


    //�� ���� �Է�
    printf("�� ���ڸ� �Է��ϼ���: ");
    scanf_s("%d %d", &num1, &num2);

    a = num1;
    b = num2;

    //�ִ����� ��� (��Ŭ���� ȣ���� ���)
    while (b != 0) {
        int temp = b; //b�� temp�� ����
        b = a % b; //a�� b�� ���� ������ ����(0�ϵɶ����� �ݺ�)
        a = temp; //a�� temp�� ���� temp=���� b��)
    }
    gcd = a;

    //�ּҰ���� ���
    lcm = (num1 * num2) / gcd;

    //��� ���
    printf("�ִ�����(GCD): %d\n", gcd);
    printf("�ּҰ����(LCM): %d\n", lcm);

    return 0;
}
