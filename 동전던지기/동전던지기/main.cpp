#include <stdio.h>

int main(void) {
    // ���� ����
    int numFlips = 10000;
    int heads = 0, tails = 0;

    // �ǻ� ������ ���� �ʱ� �õ� ��
    int seed = 1; // �ʱⰪ ���� (������ ����)

    // ���� ������ �ݺ�
    for (int i = 0; i < numFlips; i++) {
        seed += i; // �ǻ� ���� ������ ���� ����
        int result = (seed * 1103515245 + 12345) % 2; // 0 �Ǵ� 1 ����

        // ���ù��� ����Ͽ� ����� �з�
        if (result == 1) {
            heads++;
        }
        else {
            tails++;
        }
    }

    // Ȯ�� ���
    double headsProbability = (double)heads / numFlips * 100;
    double tailsProbability = (double)tails / numFlips * 100;

    // ��� ���
    printf("�� ���� ������ Ƚ��: %d\n", numFlips);
    printf("�ո�: %d�� (%.2f%%)\n", heads, headsProbability);
    printf("�޸�: %d�� (%.2f%%)\n", tails, tailsProbability);

    return 0;
}