#include <stdio.h>

// ���� ���� �Լ� (1���� 100����)
int generatePseudoRandomNumber() {
    static unsigned int seed = 12345; // ������ �õ� ��
    seed = (seed * 1103515245 + 12345) & 0x7fffffff; // �ǻ� ���� ����
    return (seed % 100) + 1; // 1���� 100������ ���ڷ� ��ȯ
}

// ���� ���� �Լ�
void playGame() {
    int target = generatePseudoRandomNumber(); // ��ǥ ���� ����
    int guess; // ����� �Է�
    int attempts = 10; // �õ� Ƚ�� ����

    printf("��ǻ�Ͱ� 1���� 100 ������ ������ �����߽��ϴ�.\n");
    printf("10���� ��ȸ �ȿ� ���ڸ� ���߼���!\n");

    for (int i = 1; i <= attempts; i++) {
        printf("�õ� %d/%d: ���ڸ� �Է��ϼ���: ", i, attempts);
        scanf_s("%d", &guess);

        if (guess < target) {
            printf("��! �� ū ���ڸ� �õ��ϼ���.\n");
        }
        else if (guess > target) {
            printf("�ٿ�! �� ���� ���ڸ� �õ��ϼ���.\n");
        }
        else {
            printf("�����մϴ�! ���ڸ� ������ϴ�!\n");
            return; // ���� ����
        }
    }

    printf("��ȸ�� ��� �����߽��ϴ�. ������ %d�����ϴ�.\n", target);
}

int main(void) {
    playGame(); // ���� ����
    return 0;
}
