#include <stdio.h>

int main(void) {
    int num;

    //�� �Է�
    printf("�� �Է� (2-9 �Ǵ� 0�Է�):");
    scanf_s("%d", &num);

    if (num == 0) {
        //0 �Է� �� ��ü ������ ���(2*1 ~ 9*9���� ���)
        for (int i = 2; i <= 9; i++) {
            printf("%d��:\n", i);
            for (int j = 1; j <= 9; j++) {
                printf("%d * %d = %d\n", i, j, i * j);
            }
            printf("\n");
        }
    }
    else if (num >= 2 and num <= 9) {
        //�Էµ� �ܸ� ���
        printf("%d��:\n", num);
        for (int i = 1; i <= 9; i++) {
            printf("%d x %d = %d\n", num, i, num * i);
        }
    }
    else {
        //��ȿx
        printf("��ȿ���� ���� ����.\n");
    }

    return 0;
}
