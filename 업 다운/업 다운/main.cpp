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

    printf("��ǻ�Ͱ� 1���� 100 ������ ���� ����.\n");
    printf("110ȸ �ȿ� ���߽ÿ�.\n");

    for (int i = 1; i <= attempts; i++) {
        printf("�õ� %d/%d: ���� �Է�: ", i, attempts);
        scanf_s("%d", &guess);

        if (guess < target) {
            printf("��.\n");
        }
        else if (guess > target) {
            printf("�ٿ�.\n");
        }
        else {
            printf("����!\n");
            return; // ���� ����
        }
    }

    printf("��ȸ ��� ����. ������ %d.\n", target);
}

int main(void) {
    playGame(); // ���� ����
    return 0;
}
