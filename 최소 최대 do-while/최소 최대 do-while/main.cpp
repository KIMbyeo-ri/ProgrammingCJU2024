#include <stdio.h>

int main(void) {
    int num1;
    int num2;
    int gcd;
    int lcm;
    int a;
    int b;

    // �� ���� �Է� �ޱ�
    printf("�� ���ڸ� �Է��ϼ���: ");
    scanf_s("%d %d", &num1, &num2);

    a = num1;
    b = num2;

    //�ִ����� ��� (��Ŭ���� ȣ���� ���)
    do {
        int temp = b;
        b = a % b;
        a = temp;
    } while (b != 0); //b�� 0�� �� ������ �ݺ�

    gcd = a;

    //�ּҰ���� ���
    lcm = (num1 * num2) / gcd;

    //��� ���
    printf("�ִ�����(GCD): %d\n", gcd);
    printf("�ּҰ����(LCM): %d\n", lcm);

    return 0;
}
